#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i] - i;
    }
    sort(begin(b) + 1, end(b));
    int mid = (n % 2 ? b[(n+1)/2] : (b[n/2] + b[n/2+1]) / 2);
    for(int i = 1; i <= n; i++){
        b[i] = abs(b[i] - mid);
    }
    cout << accumulate(begin(b) + 1, end(b), 0LL) << endl;
    return 0;
}