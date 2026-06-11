#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5 + 5;
const int K = 21;
ll ar[MAX];
int n;
ll dp[MAX];
ll sum[MAX];
int cnt[K];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    int start = 0;
    int end = 0;
    bool ok = true;
    ll sum = 0;
    ll xor_sum = 0;
    ll ans = 0;
    while (end < n){
        sum += ar[end];
        xor_sum ^= ar[end];
        if (sum == xor_sum){
            ans += (end - start + 1);
        } else{
            while (sum != xor_sum){
                sum -= ar[start];
                xor_sum ^= ar[start];
                start += 1;
            }
            ans += (end - start + 1);
        }
        end += 1;
    }
    cout << ans << "\n";
    return 0;
}