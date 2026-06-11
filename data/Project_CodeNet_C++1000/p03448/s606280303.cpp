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
const int MAX = 5*1e5;

int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int ct = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int l = 0; l <= c; l++) {
                int sum = i*500+j*100+l*50;
                if (sum == x) ct++;
            }
        }
    }
    cout << ct << endl;
}