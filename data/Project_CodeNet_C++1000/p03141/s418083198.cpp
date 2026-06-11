#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    vector<array<int, 2>> v;
    
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), [](array<int, 2> a, array<int, 2> b) {
        return a[0] + a[1] > b[0] + b[1];
    });


    long long res = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0) {
            res += v[i][0];
        }
        else res -= v[i][1];
    }
    
    cout << res << endl;

    return 0;
}
