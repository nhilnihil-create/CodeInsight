#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[22][1<<21];
int matrix[22][22];
int n;

long long solution(int man , int women){  
    if(man==n){
        return (women==((1<<n)-1)) ? 1 : 0;
    }
    if(dp[man][women] != -1){
        return dp[man][women];
    }
    
    long long ret = 0;

    for(int i=0 ; i<n ; i++){
        // cout<<"result "<<i<<" "<<man<<" "<<women<<endl;
        if(matrix[man][i]==1 && (women&(1<<i))==0){
            ret = (ret + solution(man+1 , women|(1<<i)))%mod;
        }
    }

    return dp[man][women] = ret;
}

int main(){
    
    cin>>n;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>matrix[i][j];
        }
    }


    memset(dp , -1 , sizeof(dp));
    cout<<solution(0 , 0)<<endl;

}