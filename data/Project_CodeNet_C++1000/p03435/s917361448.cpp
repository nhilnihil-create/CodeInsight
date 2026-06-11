#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
  int c[3][3];
  rep(i,3) rep(j,3) cin>>c[i][j];
  bool ok=0;
  for(int i=0;i<=c[0][0];i++){
    for(int j=0;j<=c[1][1];j++){
      for(int k=0;k<=c[2][2];k++){
        int a[3],b[3];
        a[0]=i;
        b[0]=c[0][0]-i;
        a[1]=j;
        b[1]=c[1][1]-j;
        a[2]=k;
        b[2]=c[2][2]-k;
        bool f=1;
        rep(s,3){
          rep(t,3){
            if(c[s][t]!=a[s]+b[t]) f=0;
          }
        }
        if(f) ok=1;
      }
    }
  }
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}