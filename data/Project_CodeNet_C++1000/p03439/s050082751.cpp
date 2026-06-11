#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
ll n, m, x, y,z,w, sum= 0, ans = 0;
vector<ll> a, b;
int main() {
    string st,s; cin >> n;
    cout << 0 << endl;
    int l = 0,r = n - 1;
    cin >> st;
    if (st == "Vacant") return 0;
    rep(i, 20) {
        int next = (l + r + 1) / 2;
        cout << next << endl;
        cin >> s;
        if (s == "Vacant") return 0;
        bool ok = 1;
        if (s == st && next % 2) ok = 0;
        if (s != st && next % 2 == 0)ok = 0;
        if (ok) l = next;
        else r = next;
    }
}