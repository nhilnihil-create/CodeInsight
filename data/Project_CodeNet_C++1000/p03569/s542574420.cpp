//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  string s;cin>>s;
  string t="";
  ll n=s.size();
  rep(i,n){
    if(s[i]!='x')t+=s[i];
  }
  string u=t;
  reverse(u.begin(),u.end());
  if(u!=t){
    cout<<-1<<endl;
    return 0;
  }
  ll k=t.size();
  string res=s;
  reverse(res.begin(),res.end());
  ll a=0;
  ll b=0;
  ll ans=0;
  ll j=-1,i=-1;
  ll cnta=0,cntb=0;
  while(true){
    cnta=0;
    cntb=0;
    i++;j++;
    while(i<n&&s[i]!=u[a]){
      cnta++;i++;
    }
    while(j<n&&res[j]!=u[b]){
      cntb++;j++;
    }
    a++;b++;
    //cout<<i<<" "<<j<<" "<<cnta<<" "<<cntb<<endl;
    ans+=abs(cnta-cntb);
    if(a>=(k+1)/2)break;
  }
  cout<<ans<<endl;
}
  