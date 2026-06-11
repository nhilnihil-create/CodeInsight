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
const int MAX = 100005;

int main() {
    int n; cin >> n;
    vint a(n+2,0);
    REP(i,n+1) cin >> a[i];
    int sum = 0;
    REP(i,n+2) sum += abs(a[i]-a[i-1]);
    REP(i,n+1) {
        int dif = abs(a[i]-a[i-1])+abs(a[i+1]-a[i]);
        cout << sum-dif+abs(a[i-1]-a[i+1]) << endl;
    }
}