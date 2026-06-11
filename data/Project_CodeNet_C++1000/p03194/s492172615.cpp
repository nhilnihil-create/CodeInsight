#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int64_t N, P;
    cin >> N >> P;

    vector<int64_t> v;
    map<int64_t, int64_t> m;
    int64_t i;

    if (N == 1) {
        // do nothing
    } else {
        for (i = 2; i * i <= P; i++) {
             while (P % i == 0) {
                if (m.count(i) > 0) {
                    m[i] += 1;
                } else {
                    m[i] = 1;
                }
                v.push_back(i); 
                P /= i;
             }
        }
    }

    if (P != 1) {
        v.push_back(P);
        if (m.count(P) > 0) {
            m[P] += 1;
        } else {
            m[P] = 1;
        }
    }

    int64_t ans = 1;
    for (auto p: m) {
        if (p.second < N) {
            continue;
        } else {
            ans *= static_cast<int64_t>(pow(p.first, (p.second / N)));
        }
    }
    cout << ans << endl;

    return 0;
}