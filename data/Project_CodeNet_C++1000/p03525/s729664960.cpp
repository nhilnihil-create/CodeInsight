#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

bool f(int x, vector<int>& v) {
    vector<int> a, b;
    a.push_back(0);
    b.push_back(0);
    for (int i : v) {
        if (i - a.back() >= x) a.push_back(i);
        else b.push_back(i);
    }

    rep(i, a.size() - 1) {
        if (a[i + 1] - a[i] < x) return false;
    }

    rep(i, b.size() - 1) {
        if (b[i + 1] - b[i] < x) return false;
    }

    return x <= (12 - a.back()) + (12 - b.back());
}

int main(){
    int N;
    cin >> N;

    vector<int> D(N);
    rep(i, N) cin >> D[i];

    sort(D.begin(), D.end());

    for (int i = 24; i >= 0; --i) {
        if (f(i, D)) {
            cout << i << endl;
            return 0;
        }
    }
}