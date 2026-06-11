#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;
//ここから

vector<char>t,d;
int n,q;
string s;

bool C(int mid){
  int pos=mid;
  rep(i,q){
    char now=s[pos];
    if(t[i]==now){
      if(d[i]=='L')--pos;
      else ++pos;
    }
    if(pos<=-1)return true;
  }
  return false;
}

bool C2(int mid){
  int pos=mid;
  rep(i,q){
    char now=s[pos];
    if(t[i]==now){
      if(d[i]=='L')--pos;
      else ++pos;
    }
    if(pos>=n)return true;
  }
  return false;
}

void solve(){
  cin>>n>>q;
  cin>>s;
  t.resize(q);d.resize(q);
  rep(i,q)cin>>t[i]>>d[i];
  int l=-1,r=n;
  while(r-l>1){
    int mid=(l+r)/2;
    if(C(mid))l=mid;
    else r=mid;
  }
  int left=l+1;
  l=-1,r=n;
  while(r-l>1){
    int mid=(l+r)/2;
    if(C2(mid))r=mid;
    else l=mid;
  }
  int right=n-r;
  int sub=min(n,left+right);
  cout<<n-sub<<endl;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}
