#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int get10timesVal(int x) {
    return (x + 9) / 10 * 10;
}

int getDiff(int x) {
    return get10timesVal(x) - x;
}

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    int sum = get10timesVal(A) + get10timesVal(B) + get10timesVal(C) + get10timesVal(D) + get10timesVal(E);
    sum -= max({getDiff(A), getDiff(B), getDiff(C), getDiff(D), getDiff(E)});

    cout << sum << endl;
    return 0;
}
