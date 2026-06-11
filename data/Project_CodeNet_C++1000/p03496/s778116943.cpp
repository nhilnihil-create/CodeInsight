#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n; cin >> n;
    vint a(n);
    vector<P> move;
    int tmp = 0;
    int mx, id;
    rep(i,n) {
        int x; cin >> x;
        if (chmax(tmp,abs(x))) {
            mx = x; 
            id = i;
        }
        a[i] = x;
    }
    int ct = 0;
    if (mx < 0) {
        rep(i,n) {
            if (a[i] >= 0) {
                a[i] += mx;
                ct++;
                move.push_back(P(id+1,i+1));
            }
        }
        for (int i = n-1; i >= 1; i--) {
            if (a[i-1] > a[i]) {
                a[i-1] += a[i];
                ct++;
                move.push_back(P(i+1,i));
            }
        }
    }
    if (mx > 0) {
        rep(i,n) {
            if (a[i] < 0) {
                a[i] += mx;
                ct++;
                move.push_back(P(id+1,i+1));
            }
        }
        for (int i = 0; i < n-1; i++) {
            if (a[i] > a[i+1]) {
                a[i+1] += a[i];
                ct++;
                move.push_back(P(i+1,i+2));
            }
        }
    }
    cout << ct << endl;
    rep(i,move.size()) {
        cout << move[i].first << " " << move[i].second << endl;
    }
}