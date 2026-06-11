#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
typedef pair<int, int> P;

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*
#define cin ifs
#define cout ofs
ifstream ifs("in.txt");
ofstream ofs("out.txt");
//*/
int Q;
int A[110], B[110];

signed main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i < Q; i++) {
        if (A[i] == B[i]) {
            cout << (A[i] - 1) * 2 << endl;
            continue;
        }
        if (A[i] > B[i]) swap(A[i], B[i]);
        int seki = A[i] * B[i];
        int rt = (int)sqrt(seki);
        int ans = 2 * rt - 1;
        if ((seki - 1) / rt == rt) ans--;
        if (rt * rt == seki) ans-=2;
        cout << ans << endl;
    }
    return 0;
}