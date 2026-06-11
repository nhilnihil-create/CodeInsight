#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin>>n>>k;
    int mod = 1e9 + 7;
    vector<int> candies(n+1);
    for (int i = 1; i <= n; i++)
        cin>>candies[i];
    vector<vector<int> > ways(n+1, vector<int>(k+1));
    vector<int> sum(k+1);
    sum[0] = 1;
    for (int child = 0; child <= n; child++)
        ways[child][0] = 1;
    for (int candy = 1; candy <= k; candy++) {
        ways[0][candy] = 0;
        sum[candy] = 1;
    }
    for (int child = 1; child <= n; child++) {
        for (int candy = 1; candy <= k; candy++) {
            if (candies[child] < candy) {
                ways[child][candy] = (sum[candy] - sum[candy - candies[child] -1] + mod)%mod;
            }
            else {
                ways[child][candy] = sum[candy];
            }
        }
        for (int candy = 1; candy <= k; candy++) 
            sum[candy] = (sum[candy-1] + ways[child][candy])%mod;
    }
    cout<<ways[n][k]<<"\n";
    return 0;
}
