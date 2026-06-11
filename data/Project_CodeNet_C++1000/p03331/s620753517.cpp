#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define ll long long
#define P pair<int,int>

signed main() {
    int n;
    cin >> n;

    int ans = 1e9;
    for(int i = 1; i < n; i++){
        int j = n - i;

        string a = to_string(i);
        string b = to_string(j);

        int sum = 0;
        for(auto k : a) {
            int x = k - '0';
            sum += x;
        }
        for(auto k : b) {
            int x = k - '0';
            sum += x;
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
}