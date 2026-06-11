#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long int a[n], b[n];
    long long int a_sum = 0, b_sum = 0; 
    for(int i = 0; i < n; ++i) cin >> a[i], a_sum += a[i];
    for(int i = 0; i < n; ++i) cin >> b[i], b_sum += b[i];

    long long int cnt = b_sum - a_sum;
    if(cnt < 0) {
        cout  << "No" << '\n';
        return 0;
    }
    long long int a_diff = 0, b_diff = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] > b[i]) a_diff += a[i] - b[i];
        else b_diff += (b[i] - a[i])/2;
    }
    
    if(a_diff <= b_diff) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}
