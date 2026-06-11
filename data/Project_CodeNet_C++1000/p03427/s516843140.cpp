#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string N;
    int ans = 0;
    cin >> N;
    int len = N.size();
    if (len == 1) {
        cout << N << endl;
        return 0;
    }
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += N[i] - '0'; 
    }
    ans = max(ans, total);
    for (int i = 0; i < len; i++) {
        total = 0;
        if (N[i]-'0' > 0) {
            for (int j = 0; j <= i; j++) {
                total += N[j] - '0';
            } 
            total--;
            total += 9 * (len-i-1);
            ans = max(ans, total);
            
        } else {
            continue;
        }
    }
    cout << ans << endl;
}
