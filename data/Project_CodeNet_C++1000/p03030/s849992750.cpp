#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int n;
    cin >> n;
    vector<psi> v(n);
    string S;
    int x;
    map<psi, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> S >> x;
        v[i] = psi(S, -x);
        mp[psi(S, -x)] = i + 1;
    }
    sort(v.begin(), v.end());
    for (auto p : v) {
        cout << mp[p] << '\n';
    }
}
