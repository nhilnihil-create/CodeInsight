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
const int MAX = 2e5;

const double eps = 1e-10;

int main() {
    int N; cin >> N;
    for (int h = 1; h <= 3500; h++) {
        for (int n = 1; n <= 3500; n++) {
            double a = (double)N*h*n;
            double b = (double)4*h*n-N*n-N*h;
            double w = a/b;
            if (w < 1 || w > 3500) continue;
            int tmp = int(w+eps);
            if (abs(w-tmp) < eps) {
                cout << h << " " << n << " " << tmp << endl;
                return 0;
            }
        }
    }
}