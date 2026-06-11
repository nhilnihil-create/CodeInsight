#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

#define pb push_back
#define FOR(i, s, e) for (int (i) = (s); (i) < (e); (i)++)

int N, Q;
char s[200100], t[200100], d[200100];

int C(int x) {
    FOR(i, 0, Q) {
        if(s[x] == t[i]) {
            if(x == 0) return 1;
            if(x == N + 1) return 3;
            if(d[i] == 'L') {
                x--;
            }
            else {
                x++;
            }
            
        }
    }
    if(x == 0) return 1;
    if(x == N + 1) return 3;
    return 2;
}



int main() {
    cin >> N >> Q;
    FOR(i, 1, N + 1) cin >> s[i];
    FOR(i, 0, Q) cin >> t[i] >> d[i];

    int L1 = 0, R3 = N + 1;
    while(R3 - L1 > 1) {
        int mid = (L1 + R3) / 2;
        if(C(mid) == 1) L1 = mid;
        else R3 = mid;
    }
    int L2 = R3;

    L1 = 0; R3 = N + 1;
    while(R3 - L1 > 1) {
        int mid = (L1 + R3) / 2;
        if(C(mid) == 3) R3 = mid;
        else L1 = mid;
    }
    int R2 = L1;

    cout << R2 - L2 + 1 << endl;

}
