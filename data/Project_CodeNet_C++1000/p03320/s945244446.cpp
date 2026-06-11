#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1e9+7
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(hoge) (hoge).begin(),(hoge).end()
using namespace std;
ll f(ll n){
  ll ret=0;while(n>0){ret+=n%10;n/=10;}return ret;
}
double g(ll n){return (double)(n)/f(n);}
int main(){
  ll k;cin>>k;
  vector<ll>kouho;
  ll num=1;
  for(ll i=0;i<15;i++){
    for(ll j=1;j<150;j++){
      kouho.pb(num*(j+1)-1);
    }
    num*=10;
  }
  sort(ALL(kouho));
  kouho.erase(unique(ALL(kouho)),kouho.end());
  for(ll i=0;i<kouho.size();i++)
    for(ll j=i+1;j<kouho.size();j++)
      if(g(kouho[i]) > g(kouho[j])){
	kouho.erase(kouho.begin() + i);
	i--;
	break;
      }

  for(int i=0;i<k;i++)
    cout<<kouho[i]<<endl;
  return 0;
}