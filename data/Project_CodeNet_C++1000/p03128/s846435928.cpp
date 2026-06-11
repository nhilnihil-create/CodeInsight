#include <algorithm>
#include <iostream>
using namespace std;

const int T[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    int n, m;
    cin >> n >> m;
    int a[10];
    for(int i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m, greater<int>());
    int dp[10005];
    for(int i = 0; i <= n; i++) dp[i] = -1;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int k = a[j];
            if(T[k] <= i) dp[i] = max(dp[i], dp[i - T[k]] + 1);
        }
    }
    int s = n;
    for(int i = dp[n]; i > 0; i--){
        for(int j = 0; j < m; j++){
            int k = a[j];
            if(T[k] <= s && dp[s - T[k]] == i - 1){
                s -= T[k];
                cout << k;
            }
        }
    }
    cout << endl;
}
