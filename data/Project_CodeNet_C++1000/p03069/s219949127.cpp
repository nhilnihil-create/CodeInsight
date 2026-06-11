#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; string s; cin >> n >> s;
    int cnt_w = 0;
    int cnt_b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') cnt_w++;
        if (s[i] == '#') cnt_b++;
    }
    vector<int> rev_accum_w(n + 1, 0);    
    for (int i = n - 1 ; i >= 0; i--) {
        if (s[i] == '.') rev_accum_w[i]++;
        rev_accum_w[i] += rev_accum_w[i + 1];
    }
    vector<int> accum_b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        accum_b[i] += accum_b[i - 1];
        if (s[i - 1] == '#') accum_b[i]++;        
    }
    int ans = 100000000;
    for (int i = 0; i <= n; i++) {
        int tmp = 0;
        tmp += accum_b[i];
        tmp += rev_accum_w[i];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}