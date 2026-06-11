#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const ll inf = 1e18;
const int mod = 1e5;
const int MAX = 1e6;

int main() {
    int r; cin >> r;
    if (r < 1200) cout << "ABC" << endl;
    else if (r < 2800) cout << "ARC" << endl;
    else cout << "AGC" << endl;
}