#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  if(n==3){
    cout << 2 << " " << 5 << " " << 63 << endl;
    return 0;
  }
  if(n==4){
    cout << 2 << " " << 5 << " " << 63 << " " << 20 << endl;
    return 0;
  }
  if(n==5){
    cout << 2 << " " << 3 << " " << 4 << " " << 6 << " " << 15 << endl;
    return 0;
  }
  set<int> st;
  ll sum=0;
  rep1(i,30000){
    if(i%6==0||i%6==2||i%6==3||i%6==4){
      st.insert(i);
      sum+=i;
      sum%=6;
    }
    if(st.size()==n) break;
  }
  if(sum==2){
    st.erase(8);
    st.insert(30000);
  }
  if(sum==3){
    st.erase(9);
    st.insert(30000);
  }
  if(sum==5){
    st.erase(9);
    st.insert(29998);
  }
  for(auto v:st){
    cout << v << " ";
  }cout << endl;
}
