#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    p[n-1] /= 2;
    int sum = 0;

    for(int a : p) {
        sum += a;
    }
    cout << sum << endl;
}

