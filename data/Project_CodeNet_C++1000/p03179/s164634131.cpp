#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
 freopen("input","r",stdin);
 freopen("output","w",stdout);
*/

ll MOD = 1E9 + 7;

ll A[3010], B[3010], C[3010], D[3010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string s;
    cin >> N;
    cin >> s;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    A[0] = 1;
    for (int i = 1;i < N;i++) {
        memset(B, 0, sizeof(B));
        memset(C, 0, sizeof(C));
        memset(D, 0, sizeof(D));
        C[0] = A[0];
        for (int j = 1;j < i;j++) {
            C[j] = C[j - 1] + A[j];
            C[j] %= MOD;
        }
        D[i] = 0;
        for (int j = i - 1;j >= 0;j--) {
            D[j] = D[j + 1] + A[j];
            D[j] %= MOD;
        }
        if (s[i - 1] == '<') {
            for (int j = 1;j <= i;j++) {
                B[j] = C[j - 1];
            }
        } else {
            for (int j = i - 1;j >= 0;j--) {
                B[j] = D[j];
            }
        }
        swap(A, B);
    }
    ll sol = 0;
    for (int i = 0;i < N;i++) {
        sol += A[i];
        sol %= MOD;
    }
    cout << sol << endl;
    return 0;
}
