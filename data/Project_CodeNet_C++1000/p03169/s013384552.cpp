#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> A(3);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[a-1]++;
  }
  vector<vector<vector<long double>>> B(N+2,vector<vector<long double>>(N+2,vector<long double>(N+2,0)));
  B[0][0][0]=0;
  for(int k=0;k<=N;k++){
    for(int j=0;j<=N;j++){
      for(int i=0;i<=N;i++){
        if(i)B[i][j][k]+=B[i-1][j][k]*i;
        if(j)B[i][j][k]+=B[i+1][j-1][k]*j;
        if(k)B[i][j][k]+=B[i][j+1][k-1]*k;
        if(i+j+k)B[i][j][k]=(B[i][j][k]+N)/(i+j+k);
      }
    }
  }
  cout<<fixed<<setprecision(16)<<B[A[0]][A[1]][A[2]]<<endl;
}