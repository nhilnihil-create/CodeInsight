#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<string,string> P;
const ll mod=1e9+7;

//C-String Coloring
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<P,ll> cnt;
    ll ans=0;
    rep(i,1<<n){
      string r="",b="";
      rep(j,n){
        if(i&(1<<j)){
          r+=s[j];
        }else{
          b+=s[j];
        }
      }
      cnt[P(r,b)]++;
    }
    rep(i,1<<n){
      string r="",b="";
      rep(j,n){
        if(i&(1<<j)){
          r+=s[n+j];
        }else{
          b+=s[n+j];
        }
      }
      reverse(begin(r),end(r));
      reverse(begin(b),end(b));
      ans+=cnt[P(b,r)];
    }
    cout<<ans<<endl;
}
