#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
int x[100000];
bool query(int i) {
    string V = "Vacant";
    string M = "Male";
    string F = "Female";
    cout << i << endl;
    string s;
    cin >> s;
    if (s == V) return 1;
    if (s == M) x[i] = 1;
    if (s == F) x[i] = 2;
    return 0;
}
bool check(int l, int r) {
    if (l == r) return 1;
    if (l > r) swap(l, r);
    return (x[l] == x[r] && (r-l) % 2 == 0) || (x[l] != x[r] && (r-l) % 2 == 1);
}
int main () {
    cin >> N;
    if (query(0)) return 0;
    if (query(N-1)) return 0;
    int k = 2;
    int L = 0, R = N-1;
    while (1) {
        int M = (L+R)/2;
        if (query(M)) return 0;
        k++;
        if (!check(L, M)) {
            R = M;
        }
        else if (!check(M, R)) {
            L = M;
        }
        else {

        }
        if (k == 20) {
            return 1;
        }
    }
}