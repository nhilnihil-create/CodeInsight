#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, d, x; cin >> n >> d >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int day = 1;
        int c = 1;
        while (day <= d) {
            sum++;
            day = c * a[i] + 1;
            c++;
        }
    }
 
    cout << sum + x << endl;
    return 0;
}