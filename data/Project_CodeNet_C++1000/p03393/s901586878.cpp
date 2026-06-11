#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) {rep(i,x.size()) cout << x[i] << " "; cout << endl;}
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
    string s; cin >> s;
    int n = s.size();
    if (n <= 25) {
        for (char i = 'a'; i <= 'z'; i++) {
            bool ok = true;
            rep(j,n) if (s[j] == i) ok = false;
            if (ok) {
                s += i;
                cout << s << endl;
                return 0;
            }
        }
    } else {
        while (!s.empty()) {
            for (char j = s.back()+1; j <= 'z'; j++) {
                bool ok = true;
                rep(k,s.size()-1) if (s[k] == j) ok = false;
                if (ok) {
                    s.pop_back();
                    s.push_back(j);
                    cout << s << endl;
                    return 0;
                }
            }
            s.pop_back();
        }
    }
    cout << -1 << endl;
}