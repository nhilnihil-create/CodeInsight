#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N;cin>>N;
    int A[2][N];
    int sum=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
            if(i==0){
                sum+=A[i][j];
            }
        }
    }
    sum-=A[0][0];
    int ans=A[0][0]+A[1][N-1];
    int M=sum;
    for(int i=N-1;i>=1;i--){
        sum-=A[0][i];
        sum+=A[1][i-1];
        M=max(M,sum);
    }
    ans+=M;
    cout<<ans<<endl;
    return 0;
}
