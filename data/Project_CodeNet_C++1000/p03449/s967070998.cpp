#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
int main() {
    int N;
    cin>>N;
    int A[2][N];
    for(int i=0;i<2;i++){
      for(int j=0;j<N;j++){
        cin>>A[i][j];
      }
    }
    int ans=0;
    for(int i=0;i<N;i++){
      int sumj=0;int sumk=0;
      for(int j=0;j<=i;j++){sumj+=A[0][j];}
      for(int k=i;k<N;k++){sumk+=A[1][k];}
      int sum=sumj+sumk;
      ans=max(ans,sum);
    }
    cout<<ans<<endl;

return 0;}