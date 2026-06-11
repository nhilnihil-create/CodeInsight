#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
int A[100000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A, A + n);
    int mnv = 2e9 + 5, mni = -1;
    for (int i = 0; i + 1 < n; ++i) {
        if (abs(A[i] + A[i] - A[n - 1]) < mnv) {
            mnv = abs(A[i] + A[i] - A[n - 1]);
            mni = A[i];
        }
    }
    printf("%d %d\n", A[n - 1], mni);
    return 0;
}