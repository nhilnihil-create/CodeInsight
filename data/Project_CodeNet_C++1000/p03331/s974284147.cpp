#include <bits/stdc++.h>
using namespace std;
#define v(type) vector<type>

int main() {
    int n;
    cin >> n;

    int ans = INT_MAX;    
    for (int i = 1; i < n; i++) {
        string a = to_string(i);
        string b = to_string(n-i);
        int sum = 0;
        for (int i = 0; i < a.size(); i++) sum += a[i] - '0';
        for (int i = 0; i < b.size(); i++) sum += b[i] - '0';
        ans = min(ans, sum);
    }
    cout << ans << endl;
}