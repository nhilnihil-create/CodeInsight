#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N;cin>>N;
  for(int a=1;a<=3500;a++)for(int b=a;b<=3500;b++)if(4*a*b>N*(a+b)&&N*a*b%(4*a*b-N*a-N*b)==0){
    cout<<a<<" "<<b<<" "<<N*a*b/(4*a*b-N*a-N*b)<<endl;
    return 0;
  }
  return 1;
}