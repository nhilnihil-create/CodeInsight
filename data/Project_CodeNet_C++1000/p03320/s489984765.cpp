#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,n) for(int i=a;i<(n);i++)
#define REP_sz(i,s) for(int i=0;i<s.size();i++)
#define RE return
#define FILL(a,b) memset(a,b,sizeof(a))
#define SO(a) sort(all(a))
#define pb push_back
#define sz(a) a.size()
#define V vector
#define ld long double
#define viit(a) vector<int>::iterator a
#define msit1(a) map<string,int>::iterator a
#define miit(a) map<int,int>::iterator a
#define msit2(a) map<int,string>::iterator a
#define IT iterator
#define FOR(i,a,n) for(int i=a;i<=(n);i++)
#define B(s) s.back()
#define all(a) a.begin(),a.end()
#define ER1(a) a.erase(a.begin())
#define ER0(a) a.erase(a.end())
#define pii pair<int,int>
#define pause system("PAUSE")
#define cls system("CLS")
using namespace std;
ll S(ll x){
    ll ans=0;
    string s=to_string(x);
    REP(i,0,s.size())ans+=(s[i]-'0');
    return ans;
}
int main(){
  ll k;
  cin>>k;
  ll ans=1;
  ll d=1;
  REP(i,0,k){
    cout<<ans<<endl;
    if(1.0*(ans+d)/S(ans+d)>d) d*=10;
    ans+=d;
  }
  return 0;
}