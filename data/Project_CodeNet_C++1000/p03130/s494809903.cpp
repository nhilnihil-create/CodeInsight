#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> cnt(4);
    for (int i=0; i<6; ++i) {
        int num; cin >> num;
        num--;
        cnt[num]++;
    }
    sort(cnt.begin(), cnt.end());
    bool ans = false;
    vector<int> can = {1, 1, 2, 2};
    if (cnt == can) ans = true;
    cout << (ans ? "YES" : "NO") << endl;
}