#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans;
    for (ans=999; ans>=n + 111; ans -= 111) {}
    cout << ans << endl;
}