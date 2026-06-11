#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    int n;
    cin >> n;

    vector<int64_t> a(n);
    int64_t min_a = INT_MAX, sum = 0;
    bool flg = false;
    for (auto i = 0; i < n; i++) {
        cin >> a[i];
        min_a = min(min_a, abs(a[i]));
        sum += abs(a[i]);
        if(a[i] < 0) flg = not(flg);
    }

    if(flg) sum -= min_a * 2;
    cout << sum << endl;
    return 0;
}