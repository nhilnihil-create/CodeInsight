#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int N, A[200000];

bool check(int n) {
    map<int, int> mii;
    int before = 0;
    REP(i, N) {
        if (A[i] <= before) {
            vector<int> target;
            for (auto it = mii.rbegin(); it != mii.rend(); it++) {
                if (it->first >= A[i]) target.push_back(it->first);
                else break;
            }
            for (int j : target) mii.erase(j);

            target.clear();
            bool ok = false;
            RREP(j, A[i]) {
                if (mii.find(j) != mii.end() && mii[j] == n - 1) target.push_back(j);
                else {
                    mii[j]++;
                    ok = n != 1;
                    break;
                }
            }
            for (int j : target) mii.erase(j);
            if (!ok) return false;
        }
        before = A[i];
    }
    return true;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];
    int ng = 0, ok = 300000;
    while (ok - ng > 1) {
        int mid = (ng + ok) / 2;
        if (check(mid)) ok = mid;
        else            ng = mid;
    }
    cout << ok << endl;
    return 0;
}
