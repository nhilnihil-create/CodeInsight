#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> cnt(4, 0);
    int x;
    for (int i = 0; i < 6; i++) cin >> x, cnt[x - 1]++;
    bool flag = true;
    for (int i = 0; i < 4; i++) if (cnt[i] == 3) flag = false;
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}