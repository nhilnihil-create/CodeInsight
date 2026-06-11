#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>DP(200000,int(1e9+7));
  DP[0]=0;
  vector<int>A{1,6,36,216,1296,7776,46656,9,81,729,6561,59049};
  for(int i=0;i<N;i++)
    for(int j=0;j<12;j++)
      DP[i+A[j]]=min(DP[i+A[j]],DP[i]+1);
  cout<<DP[N]<<endl;
}