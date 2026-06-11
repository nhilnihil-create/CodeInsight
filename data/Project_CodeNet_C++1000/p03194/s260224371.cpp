#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
ll N,P,ans=1;
cin>>N>>P;
if(N==1){
printf("%lld\n",P);
return 0;
}
for(ll i=2;pow(i,N)<=P;i++){
ll tmp=pow(i,N);
if(P%tmp==0)
ans = i;
}
printf("%lld\n",ans);
}
