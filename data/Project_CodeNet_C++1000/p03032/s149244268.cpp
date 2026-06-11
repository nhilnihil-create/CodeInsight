#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50 + 5;
const long long MOD = 1e9 + 7;

typedef long long ll;

int n, k;
int arr[MAX_N];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= min(k, n); i++) {
        for (int j = 0; j <= i; j++) {
            vector<int> tmp;
            for (int h = 1; h <= j; h++) tmp.push_back(arr[h]);
            for (int h = n; h >= n - (i - j) + 1; h--) tmp.push_back(arr[h]);
            sort(tmp.rbegin(), tmp.rend());
            for (int h = 0; h < k - i && !tmp.empty() && tmp.back() < 0; h++)
                tmp.pop_back();
            int cur = 0;
            for (int x : tmp)
                cur += x;
            ans = max(ans, cur);
        }
    }
    cout << ans;
}

