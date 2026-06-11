#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int A[510][510];
int B[251000][4];

int main(){
  int h,w;
  cin>>h>>w;
  
  int x;
  rep(i,h){
    rep(j,w){
      cin>>x;
      A[i+1][j+1]=x%2;
    }
  }
  
  int k=0;
  bool b=false;
  int tmph,tmpw;
  for(int i=1;i<=h;i++){
    if(i%2==1){
      for(int j=1;j<=w;j++){
        if(b==false && A[i][j]%2==1){
          tmph=i,tmpw=j;
          b=true;
        }
        else if(b==true){
          B[k][0]=tmph,B[k][1]=tmpw,B[k][2]=i,B[k][3]=j;
          k++;
          if(A[i][j]%2==1) b=false;
          else tmph=i,tmpw=j;
        }
      }
    }
    else{
      for(int j=w;j>=1;j--){
        if(b==false && A[i][j]%2==1){
          tmph=i,tmpw=j;
          b=true;
        }
        else if(b==true){
          B[k][0]=tmph,B[k][1]=tmpw,B[k][2]=i,B[k][3]=j;
          k++;
          if(A[i][j]%2==1) b=false;
          else tmph=i,tmpw=j;
        }
      }
    }
  }
  
  cout<<k<<endl;
  rep(i,k) cout<<B[i][0]<<" "<<B[i][1]<<" "<<B[i][2]<<" "<<B[i][3]<<endl;

  return 0;
}