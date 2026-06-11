#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    map<int, int> a;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    int ans = 0;
    for (auto a_tmp : a)  {
        if (a_tmp.first < a_tmp.second)
            ans += (a_tmp.second-a_tmp.first);
        else if (a_tmp.second < a_tmp.first)
            ans += a_tmp.second;
    }
    cout << ans << endl;
}