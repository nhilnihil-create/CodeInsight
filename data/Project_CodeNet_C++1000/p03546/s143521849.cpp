#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 100100100100100100;
const ll V = 10;
ll D[V][V];
void WarshallFloyd(){
  ll i,j,k;
  for(i=0;i<V;i++){
    for(j=0;j<V;j++) scanf("%lld",&D[i][j]);
  }
  for(k=0;k<V;k++){
    for(i=0;i<V;i++){
      for(j=0;j<V;j++) D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
    }
  }
}
int main(){
  ll h,w,i,a,ans = 0;scanf("%lld%lld",&h,&w);
  WarshallFloyd();
  for(i=0;i<h*w;i++){
    scanf("%lld",&a);
    if(a!=-1) ans += D[a][1];
  }
  printf("%lld\n",ans);
}