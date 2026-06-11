#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> even(100000 + 10, 0), odd(100000 + 10, 0);
    for (int i = 0; i < n; i += 2) {
        odd[v[i]]++;
    }
    for (int i = 1; i < n; i += 2) {
        even[v[i]]++;
    }
    class Max {
       public:
        int cntmax = -1;
        int cntsecond = -1;
        int nummax = -1;
        Max(int cm, int cs, int nm) {
            cntmax = cm;
            cntsecond = cs;
            nummax = nm;
        }
    };
    Max odds(odd[0], odd[1], 0), evens(even[0], even[1], 0);
    for (int i = 1; i < 100000 + 10; i++) {
        if (odds.cntmax < odd[i]) {
            odds.cntsecond = odds.cntmax;
            odds.cntmax = odd[i];
            odds.nummax = i;
        } else if (odds.cntsecond < odd[i]) {
            odds.cntsecond = odd[i];
        }
        if (evens.cntmax < even[i]) {
            evens.cntsecond = evens.cntmax;
            evens.cntmax = even[i];
            evens.nummax = i;
        } else if (evens.cntsecond < even[i]) {
            evens.cntsecond = even[i];
        }
    }
    int ans;
    if (odds.nummax == evens.nummax) {
        ans = n -
              max(odds.cntmax + evens.cntsecond, odds.cntsecond + evens.cntmax);
    } else {
        ans = n - odds.cntmax - evens.cntmax;
    }
    cout << ans << endl;
    return 0;
}