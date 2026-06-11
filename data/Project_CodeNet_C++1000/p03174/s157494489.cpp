#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
const ll MOD=1000000007;
ll dp[1<<21];
bool mat[21][21];

int cntOnes(int x) {
    int y=0;
    while(x>0) {
        y+=x%2;
        x/=2;
    }
    return y;
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) {
            cin >> mat[i][j];
        }
    }

    dp[0]=1;
    for (int mask=0;mask<(1<<n);mask++) {
        int a=cntOnes(mask);
        for (int b=0;b<n;b++) {
            if (mask&(1<<b) || mat[a][b]==0) {continue;}
            int mask2=(mask|(1<<b));
            dp[mask2]+=dp[mask];
            dp[mask2]%=MOD;
        }
    }
    cout << dp[(1<<n)-1] << endl;

}
