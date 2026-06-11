#include <bits/stdc++.h>
using namespace std;

bool isOK(int k, string s) {
    int len = (int)s.size();
    if (k * 2 <= len) return true;

    int cnt = 0;
    for (int i = len - k; i < k; i++)
    {
        if (s.at(i) == '0') cnt++;
    }
    if (cnt == k * 2 - len || cnt == 0) return true;
    else return false;
}

int binary_search(int len, string s) {
    int ng = len + 1;
    int ok = 1;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, s)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    string s;
    cin >> s;

    int ans = binary_search((int)s.size(), s);
    cout << ans << endl;
}
