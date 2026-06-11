#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int v[100000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    map<int, int> m1;
    map<int, int> m2;
    for (int i = 0; i < n; i += 2) m1[v[i]]++;
    for (int i = 1; i < n; i += 2) m2[v[i]]++;

    int evenMaxCount = 0;
    int evenMax = 0;
    for (pair<int, int> p : m1) {
        if (p.second > evenMaxCount) {
            evenMaxCount = p.second;
            evenMax = p.first;
        }
    }

    int oddMaxCount = 0;
    int oddMax = 0;
    for (pair<int, int> p : m2) {
        if (p.second > oddMaxCount) {
            oddMaxCount = p.second;
            oddMax = p.first;
        }
    }

    if (evenMax == oddMax) {
        int even2ndCount = 0;
        int even2nd = 0;
        for (pair<int, int> p : m1) {
            if (p.second > even2ndCount && p.first != evenMax) {
                even2ndCount = p.second;
                even2nd = p.first;
            }
        }

        int odd2ndCount = 0;
        int odd2nd = 0;
        for (pair<int, int> p : m2) {
            if (p.second > odd2ndCount && p.first != oddMax) {
                odd2ndCount = p.second;
                odd2nd = p.first;
            }
        }
        
        if (even2ndCount >= odd2ndCount) evenMax = even2nd;
        else oddMax = odd2nd;
    }

    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (v[i] != evenMax) ans++;
    }
    for (int i = 1; i < n; i += 2) {
        if (v[i] != oddMax) ans++;
    }

    cout << ans << endl;
}