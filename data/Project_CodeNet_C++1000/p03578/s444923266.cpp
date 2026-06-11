#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
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
    map<int, int> mp;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        mp[k]++;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        mp[k]--;
    }

    bool chk = true;
    for (auto f : mp) {
        if (f.second < 0) chk = false;
    }

    cout << (chk ? "YES\n" : "NO\n");

}
