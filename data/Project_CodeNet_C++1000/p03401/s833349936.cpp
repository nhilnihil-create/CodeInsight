#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll sum =0;
    vector<int> a(n+2);
    a[0]=0;
    a[n+1]=0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] ;
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        sum += abs(a[i+1]-a[i]);
        b[i] = abs(a[i+2]-a[i+1])+abs(a[i+1]-a[i])-abs(a[i+2]-a[i]);
    }
    sum += abs(a[n]);

    for(int i = 0; i < n; i++) {
        cout << sum - b[i] << endl;
    }
    return 0;
}