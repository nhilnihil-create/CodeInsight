#include "bits/stdc++.h"
using namespace std;

int main() {
    vector<int> AB(6);
    vector<int> cnt(4);
    for (int i = 0; i < 6; i++) {
        cin >> AB[i];
        cnt[AB[i] - 1]++;
    }

    int res1 = 0, res2 = 0;
    for (int i = 0; i < 4; i++) {
        if (cnt[i] == 1) res1++;
        else if (cnt[i] == 2) res2++;
    }
  
    if (res1 == 2 && res2 == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}