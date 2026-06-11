#include <iostream>
#include <cstdlib>
#include <iomanip>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0);
const int M = 1e9+7;
using namespace std;
bool connected[25][25];
ll dp[1<<22];


int main(){
    AC
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>connected[i][j];
        }
    }
    
    dp[0] = 1;
    for(int i=1; i<(1<<n); i++){
        int v = __builtin_popcount(i)-1;
        for(int j=0; j<n; j++){
            if(connected[v][j] && ((1<<j)&i))
                dp[i]+=(dp[i-(1<<j)]%M);
        }
    }

    cout<<dp[(1<<n)-1]%M<<endl;

}