#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 100005;

bool is_prime(int a) {
    bool ok = true;
    if (a == 1) return false;
    if (a == 2) return true;
    else {
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) ok = false;
        }
        return ok;
    }
}

int main() {
    //エラストテネスの篩
    int mx = 55555;
    vector<bool> prime(mx+1,true);
    prime[1] = false;
    for (int i = 2; i <= mx; i++) {
        if (prime[i]) {
            for (int j = 2*i; j <= mx; j += i) prime[j] = false;
        }
    }
    int n; cin >> n;
    vint x;
    for (int i = 2; i <= mx; i++) {
        if (i % 5 != 1) continue;
        if (prime[i]) {
            x.push_back(i);
        }
    }
    rep(i,n) {
        if (i == n-1) cout << x[i] << endl;
        else cout << x[i] << " ";
    }
}