#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;

    vector<int> ans; ll cur = 0, p = 1;
    REP(i, 0, 64) {
        if ((N - cur) % abs(p * 2) != 0) {
            cur += p;
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
        p *= (-2);
        if (cur == N) break;
    }

    for (auto itr = ans.rbegin(); itr != ans.rend(); itr++) cout << *itr;
    cout << endl;
    return 0;
}