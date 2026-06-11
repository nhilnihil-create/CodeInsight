#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int a[n];

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a, a + n);

    long long mid = (n%2 ? a[n/2] : (a[n/2] + a[n/2]) / 2);

    long long sum = 0;
    for(int i = 0; i < n; ++i) sum += abs(a[i] - mid);
    cout << sum;
}
