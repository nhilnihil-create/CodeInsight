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
int n;
ll dp[405][405];
ll arr[405];


int main(){
    AC
    cin>>n;
    arr[0] = 0;
    for(int i=1; i<=n; i++){
        ll x;
        cin>>x;
        arr[i] = x+arr[i-1];
    }

    for(int l=2; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int end = i+l-1;
            dp[i][end] = dp[i][i]+dp[i+1][end]+(arr[i+1]-arr[i])+(arr[end+1]-arr[i+1]);
            for(int k=i+1; k<=end; k++){
                dp[i][end] = min(dp[i][end], dp[i][k]+dp[k+1][end]+(arr[k+1]-arr[i])+(arr[end+1]-arr[k+1]));
            }
        }
    }

    cout<<dp[0][n-1]<<endl;
}