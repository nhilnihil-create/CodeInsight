#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const ll inf = 1e18;

int main() {
    int n, i;
    cin >> n >> i;
    cout << n - i + 1 << endl;
}