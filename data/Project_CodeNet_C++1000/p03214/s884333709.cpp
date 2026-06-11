#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i], ans += a[i];
    int gap = 1e9;
    int id = - 1;
    for (int i = 0; i < n; i++) {
        if (abs(ans - a[i] * n) < gap) gap = abs(ans - a[i] * n), id = i;
    }
    cout << id << endl;
}