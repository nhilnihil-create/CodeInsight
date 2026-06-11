#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <unordered_set>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0);
using namespace std;
const int N = 1e5;
const int M = 1e9+7;
int n, k;
ll dp[105][N+5];
int arr[105];


int main(){
    AC
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<=arr[0]; i++){
        dp[0][i] = 1;
    }

    for(int i=1; i<n; i++){
        dp[i][0] = 1;
        for(int j=1; j<=k; j++){
            if(j<=arr[i])
                dp[i][j] = (dp[i][j-1]+dp[i-1][j])%M;
            else{
                //if(j-1==arr[i])
                 //   dp[i][j] = ((dp[i][j-1]-dp[i][j-arr[i]-1])+dp[i-1][j])%M;
                dp[i][j] = (dp[i][j-1]-dp[i-1][j-arr[i]-1]+dp[i-1][j]+M)%M;
            }
            /*
            for(int z=j; z>=j-arr[i]&&z>=0; z--){
                dp[i][j]+=dp[i-1][z];
                dp[i][j]%=M;
            }
           */ 
        }
    }

    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    */
    cout<<dp[n-1][k]<<endl;

}
