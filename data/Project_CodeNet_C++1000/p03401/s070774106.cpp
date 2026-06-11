#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];    
    
    int sum = 0;
    vector<int> d(n);
    for (int i = 0; i < n + 1; i++) {
        if (i == 0) {
            d[i] = abs(a[i]);
        }
        else if (i == n) {
            d[i] = abs(a[i - 1]);
        }
        else {
            d[i] = abs(a[i] - a[i - 1]);            
        }
        sum += d[i];
    }

    
    for (int i = 0; i < n; i++) {
        int tmpSum = sum;
        tmpSum -= d[i] + d[i + 1];
        
        if (i == 0) {
            tmpSum += abs(a[1]);
        }
        else if (i == n - 1) {
            tmpSum += abs(a[n - 2]);
        }
        else {
            tmpSum += abs(a[i + 1] - a[i - 1]);
        }

        cout << tmpSum << endl;
    }

    return 0;
}