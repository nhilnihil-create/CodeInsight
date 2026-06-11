#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; ++i)

const int MAX = 2e5+10;

int N;
int A[MAX];

bool check(int n) {
    map<int, int> m; // m[i]: i文字目のアルファベット、iが存在しないときはm[i] = 0

    REP (i, N-1) {
        if (A[i+1] > A[i]) continue;
        int a = A[i+1];
        while (m[a] == n-1) {
            a--;
            if (a <= 0) return false;
        }
        
        m[a]++;
        // インクリメントした文字以降は全て0にリセット
        auto it = m.upper_bound(a);
        while (it != m.end()) it = m.erase(it);
    }
    return true;
}

bool isIncreasing() {
    REP (i, N-1) {
        if (A[i+1] <= A[i]) return false;
    }
    return true;
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    if (isIncreasing()) {
        cout << 1 << endl;
        return 0;
    }
    int lo = 1, hi = N+1;
    while (hi - lo > 1) {
        int mid = (hi+lo)/2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }

    cout << hi << endl;
}