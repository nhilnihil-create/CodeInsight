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
  vector<ll> beki2;
  ll i=1;
  while(i<=2e9){
    beki2.push_back(i);
    i*=2;
  }
  reverse(all(beki2));
  int n; cin >> n;
  multiset<ll> st;
  rep(i,n){
    int a; cin >> a;
    st.insert(a);
  }
  ll ans=0;
  while(st.size()){
    int x=*rbegin(st);
    st.erase(st.find(x));
    rep(j,beki2.size()){
      if(st.count(beki2[j]-x)){
        st.erase(st.find(beki2[j]-x));
        ans++;
      }
    }
  }
  cout << ans << endl;
}