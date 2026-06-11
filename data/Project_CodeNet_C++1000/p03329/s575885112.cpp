#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int M[12]={1,6,36,216,1296,7776,46656,9,81,729,6561,59049};
  int DP[100010];
  for(int i=1;i<=100009;i++){
    DP[i]=50;
  }
  DP[0]=0;
  
  for(int i=0;i<100000;i++){
    for(int j=0;j<12;j++){
      if(i+M[j] <100005 && DP[i+M[j]] > DP[i]+1){
        DP[i+M[j]]=DP[i]+1;
      }
    }
  }
  cout<<DP[N]<<endl;
  return 0;
}

        