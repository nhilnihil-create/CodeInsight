#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll n;
  cin >> n;
  ll i,j,ans,ans1,ans2;
  for(i=1;i<=3500;i++){
    for(j=1;j<=3500;j++){
      if((4*i*j-n*j-n*i)<=0){
        continue;
      }
      if((n*i*j)%(4*i*j-n*j-n*i)==0){
        ans=(n*i*j)/(4*i*j-n*j-n*i);
        ans1=i,ans2=j;
        break;
      }
    }
  }
  printf("%lld %lld %lld\n",ans1,ans2,ans);
}