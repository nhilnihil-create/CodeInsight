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
#include<random>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

ll gcd(ll n, ll m) {
	ll tmp;
	while (m!=0) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m) {
	return abs(n) / gcd(n, m)*abs(m);//gl=xy
}
 
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

void solve(){
  int n;
  cin>>n;
  if(n==3){
    cout<<2<<" "<<3<<" "<<25;
    return;
  }
  if(n==4){
    cout<<2<<" "<<5<<" "<<20<<" "<<63;
    return;
  }  
  if(n==5){
    cout<<2<<" "<<5<<" "<<20<<" "<<30<<" "<<63;
    return;
  }
  set<int>st;
  st.emplace(2);st.emplace(3);
  int num=4;
  while(st.size()<n){
      if((num%2==0)||(num%3==0))st.emplace(num),++num;
      else ++num;
  }
  ll sum=0;
  for(auto x:st){
    sum+=x;
  }
  if(sum%6==2){
    st.erase(8);
    while(num%6!=0)++num;
    st.emplace(num);
  }
  else if(sum%6==3){
    st.erase(9);
    while(num%6!=0)++num;
    st.emplace(num);
  }
  else if(sum%6==5){
    st.erase(8);
    while(num%6!=3)++num;
    st.emplace(num);
  }
  for(auto x:st){
    cout<<x<<" ";
  }
  cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
