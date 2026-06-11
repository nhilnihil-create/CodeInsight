#include <bits/stdc++.h>
using namespace std;
typedef pair<double,int> pp;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int p = a[n-1];
    int q = 0;
    int m = min(a[0], a[n-1] - a[0]);
    for(int i=1; i + 1 < n; ++i) {
        if(min(a[i], a[n-1]-a[i]) > m) {
            m = min(a[i], a[n-1]-a[i]);
            q = i;
        }
    }

    cout << p << ' ' << a[q] << endl;
}