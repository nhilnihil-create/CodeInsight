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
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
int main(){
  ll n;cin>>n;
  vector<string>s(n);
  rep(i,n)cin>>s[i];
  ll count=0,a=0,b=0,ab=0;
  rep(i,n){
    rep(j,s[i].size()-1){
      if(s[i][j]=='A'&&s[i][j+1]=='B')count++;
    }
    if(s[i][0]=='B'&&s[i][s[i].size()-1]!='A')b++;
    if(s[i][0]!='B'&&s[i][s[i].size()-1]=='A')a++;
    if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A')ab++;
  }
  if(ab==0)cout<<count+min(a,b)<<endl;
  else if(a+b==0)cout<<count+ab-1<<endl;
  else cout<<count+ab+min(a,b)<<endl;
}