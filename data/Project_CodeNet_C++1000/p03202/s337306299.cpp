#include <bits/stdc++.h>

using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int N;
int A[220000];

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++)cin >> A[i];
    for (int i = 1; i < N; i++)if (A[i - 1] >= A[i])goto aoba;
    cout << 1 << endl;
    return 0;
    aoba:;
    int lb = 1, ub = N + 1;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        map<int, int> mp;
        for (int i = 1; i < N; i++) {
            if (A[i - 1] >= A[i]) {
                for (auto it = mp.upper_bound(A[i]);
                     it->first <= A[i - 1] && it != mp.end(); it = mp.upper_bound(A[i])) {
                    mp.erase(it);
                }
                for (int j = A[i]; j > 0; j--) {
                    if (mp[j] == mid - 1)mp.erase(j);
                    else {
                        mp[j]++;
                        goto umiko;
                    }
                }
                lb = mid;
                goto nene;
            }
            umiko:;
        }
        ub = mid;
        nene:;
    }
    cout << ub << endl;
}
