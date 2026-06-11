#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int>a(N);
    vector<int>b(N);
    ll total_a = 0;
    ll total_b = 0;
    ll count = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        total_a += a[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        total_b += b[i];
    }

    count = total_b - total_a;

    ll res = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] < b[i]) {
            res += ceil((double)(b[i]-a[i])/2.0);
        }
    }
    if (res <= count) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
