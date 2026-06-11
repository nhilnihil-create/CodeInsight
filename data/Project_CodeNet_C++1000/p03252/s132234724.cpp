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
    string S;
    string T;
    cin >> S >> T;

    vector<vector<int> > vS(26, vector<int>()), vT(26, vector<int>());

    for (int i = 0; i < S.size(); i++) { vS[S[i] - 'a'].push_back(i); }
    for (int i = 0; i < S.size(); i++) { vT[T[i] - 'a'].push_back(i); }

    vector<string> sS, sT;
    for (auto v : vS) {
        string tmp = "";
        for (int vi : v) { tmp += to_string(vi); }
        sS.push_back(tmp);
    }
    for (auto v : vT) {
        string tmp = "";
        for (int vi : v) { tmp += to_string(vi); }
        sT.push_back(tmp);
    }

    sort(sS.begin(), sS.end());
    sort(sT.begin(), sT.end());

    if (sS == sT) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
