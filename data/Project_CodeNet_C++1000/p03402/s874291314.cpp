#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007

int main(){
  int A,B;
  cin>>A>>B;
  int H=100;
  int W=100;
  vector<vector<char>> c(H,vector<char>(W));
  for(int i=0;i<H/2;i++){
    for(int j=0;j<W;j++){
      c[i][j]='.';
    }
  }
  for(int i=H/2;i<H;i++){
    for(int j=0;j<W;j++){
      c[i][j]='#';
    }
  }
  A--;
  B--;

  for(int i=0;i<H/2;i+=2){
    for(int j=0;j<W;j+=2){
      if(B==0){
        break;
      }
      c[i][j]='#';
      B--;
    }
  }
  for(int i=H/2+1;i<H;i+=2){
    for(int j=0;j<W;j+=2){
      if(A==0){
        break;
      }
      c[i][j]='.';
      A--;
    }
  }
  
  cout<<H<<" "<<W<<endl;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout<<c[i][j];
    }
    cout<<endl;
  }
}
