#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector< vector<int> > a(n, vector<int>(n));
    vector< long long > dp((1<<n), 0), cst((1<<n), 0);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];

    for(int i=0;i<(1<<n);i++){
        cst[i] = 0;
        for(int j=0;j<n;j++){
            if(((i>>j)&1)==0) continue;
            for(int k=j+1;k<n;k++){
                if(((i>>k)&1)==1) cst[i] += a[j][k];
            }
        }
    }

    for(int i=0;i<(1<<n);i++){
        for(int j=i;j>0;j=((j-1)&i)){
            dp[i] = max(dp[i], dp[i-j]+cst[j]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
}
