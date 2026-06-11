#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m + 1);
    //printVector(v);
    for (int i = 0; i <= n - 1; i++) {
        int k;
        cin >> k;
        for (int j = 0; j <= k - 1; j++) {
            //cout << j << '\n';
            int a;
            cin >> a;
            v[a]++;
            //printVector(v);
        }
    }
    //printVector(v);
    int count = 0;
    for (int i = 0; i <= m; i++) {
        //cout << v[i] << '\n';
        if (v[i] == n) count++;
    }
    cout << count << '\n';
    return 0;
}