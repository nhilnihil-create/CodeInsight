#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n; n--;

    vector<int> c(n), s(n), f(n);
    for(auto i = 0; i < n; i++) cin >> c[i] >> s[i] >> f[i];

    for (auto i = 0; i < n; i++) {
        auto t = s[i] + c[i];
        for (auto j = i + 1; j < n; j++) {
           if(s[j] >= t) t = s[j];
           else if((t - s[j]) % f[j] != 0) t += f[j] - (t % f[j]);
           t += c[j];
        }
        cout << t << endl;
    }

    cout << 0 << endl;
    return 0;
}