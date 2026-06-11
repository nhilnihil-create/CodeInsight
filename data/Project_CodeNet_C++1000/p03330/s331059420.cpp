#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,C;
  cin>>N>>C;
//メモ
  vector<vector<int>> A(3,vector<int>(C+1,0));
  int CC[C+1][C+1];
  for(int i=1; i<=C; i++){
    for(int j=1; j<=C; j++){
      int c;
      cin>>c;
      CC[i][j]=c;
    }
  }
  int NN[N+1][N+1];
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      int n;
      cin >>n;
      NN[i][j]=n;
    }
  }
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if((i+j)%3==0)
        A[0][NN[i][j]]++;
      if((i+j)%3==1)
        A[1][NN[i][j]]++;
      if((i+j)%3==2)
        A[2][NN[i][j]]++;
    }
  }
  int ans=1e9;
  for(int i=1; i<=C; i++){
    for(int j=1; j<=C; j++){
      for(int k=1; k<=C; k++){
        if(i==j || j==k || k==i)
          continue;
        int tmp0=0, tmp1=0, tmp2=0;
        for(int n=1; n<=C; n++){
          tmp0+=CC[n][i]*A[0][n];
          tmp1+=CC[n][j]*A[1][n];
          tmp2+=CC[n][k]*A[2][n];
        }
        ans=min(ans,tmp0+tmp1+tmp2);
      }
    }
  }
  cout<<ans<<endl;
}