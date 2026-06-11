#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int>c(N-1);
    vector<int>s(N-1);
    vector<int>f(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }

    for (int i = 0; i < N; i++) {
        int now = 0;
        if (i == N-1) {
            cout << 0 << endl;
        } else {
            int cnt = 0;
            for (int j = i; j < N-1; j++) {
                if (cnt == 0) {
                    now += s[j]+c[j];
                } else {
                    if (now < s[j]) {
                        now = s[j] + c[j];
                    } else {
                        now = s[j] + ceil((double)(now-s[j])/(double)f[j]) * f[j] + c[j];
                    }
                }
                cnt++;
            }
            cout << now << endl;
        }
    }
}
