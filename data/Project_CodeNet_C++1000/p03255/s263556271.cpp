#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
ll N,X;
vll x,s;
int main(){
  cin>>N>>X;
  rep(i,N){
    ll a;
    cin>>a;
    x.pb(a);
  }
  reverse(x.begin(),x.end());
  s.pb(0);
  rep1(i,x.size()){
    s.pb(s[i-1]+x[i-1]);
  }
  ll res=INFLL;
  rep1(i,N){
    ll temp=0;
    bool f=false;
    temp+=(N+i)*X;
    temp+=s[i]*5;
    if(temp>=res) continue;
    ll j=i+i,k=2;
    while(j<=N){
      temp+=(s[j]-s[j-i])*(2*k+1); 
      if(temp>=res){
	f=true;
	break;
      }     
      k++;
      j+=i;
    }
    if(f) continue;
    temp+=(s[N]-s[j-i])*(2*k+1);
    res=min(res,temp);
  }
  prin(res);
  return 0;
}
