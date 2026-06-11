#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    int n; cin >> n;
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int time = 0;
        time += s[i];
        time += c[i];
        for (int j = i + 1; j < n - 1; j++) {
            if (s[j] < time) {
                if (time % f[j] != 0) {
                    int diff = time % f[j];
                    time += f[j] - diff;
                }
            }
            else { // time <= s[j]
                time = s[j];
            }        
            time += c[j];
        }
        cout << time << endl;
    }
    cout << 0 << endl;
    return 0;
}