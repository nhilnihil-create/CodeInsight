#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>
#define int ll

main(){
  int n;
  cin>>n;
  int Cx,Cy,H;
  vector<int> x(n),y(n),h(n);
  rep(i,n) cin>>x[i]>>y[i]>>h[i];
  bool flag=0;
  for(int i=0; i<=100; i++){
    for(int j=0; j<=100; j++){
      bool ok=1;
      H=0;
      int limit=INT_MAX;
      rep(k,n){
        if(H==0){
          if(h[k]!=0){
            H=h[k]+abs(i-x[k])+abs(j-y[k]);
            if(H>limit) ok=0;
          }
          else limit=min(limit,h[k]+abs(i-x[k])+abs(j-y[k]));
        }else{
          if(h[k]!=max(H-abs(i-x[k])-abs(j-y[k]),0LL)) ok=0;
        }
      }
      if(ok){
        flag=1; Cx=i; Cy=j; break; 
      }
    }
    if(flag)break;
  }
  cout<<Cx<<" "<<Cy<<" "<<H<<endl;
}
