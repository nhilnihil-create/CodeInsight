#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int A[100000];
ll N;
int bit[200001];

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x) {
    while (i <= 200000) {
        bit[i] += x;
        i += i & -i;
    }
}

bool check(int n) {
    vector<int> vi = {0};
    REP(i, N) {
        if (A[i] >= n) vi.push_back(vi[i] + 1);
        else vi.push_back(vi[i] - 1);
    }

    fill(bit, bit + 200001, 0);
    ll c = 0;
    REP(i, vi.size()) {
        c += i - sum(vi[i] + 100000);
        add(vi[i] + 100000, 1);
    }
    ll c_max = (N + 1) * N / 2;
    return c <= c_max / 2;
}

int main() {
    int sorted[100000];
    cin >> N;
    REP(i, N) cin >> A[i];
    REP(i, N) sorted[i] = A[i];
    sort(sorted, sorted + N);

    int ok = 0, ng = N;
    while (ng - ok > 1) {
        int mid = (ng + ok) / 2;
        if (check(sorted[mid])) ok = mid;
        else                    ng = mid;
    }
    cout << sorted[ok] << endl;
    return 0;
}