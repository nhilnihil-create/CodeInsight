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
    vector<pp> b(n-1);
    for(int i=0; i<n-1; ++i) b[i] = pp(fabs(a[i] - (double)p / (double)2), i);
    sort(b.begin(), b.end());
    int q = a[b[0].second];

    cout << p << ' ' << q << endl;
}