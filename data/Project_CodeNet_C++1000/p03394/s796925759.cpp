#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
ll pow(ll a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

/*
void small() {
 
    rep3(i, 2, 20) rep3(j, 2, 20) rep3(k, 2, 20) rep3(l, 2, 20) rep3(m, 2, 20) {
        if (gcd(i, gcd(j, gcd(k, gcd(l, m)))) != 1) continue;
        int sum = i + j + k + l + m;
        if (gcd(i, sum) == 1 || gcd(j, sum) == 1 || gcd(k, sum) == 1 || gcd(l, sum) || gcd(m, sum) == 1) continue;
        cout << i << " " << j << " " << k << " " << l << " " << m << '\n';
        return;
    }
 
    int a[] = {2, 5, 20, 63};
    int sum = 0;
    rep(i, 4) sum += a[i];
    rep3(i, 2, 100) {
        if (gcd(sum, i) == 1) continue;
        int flg = 0;
        rep(j, 4) if (gcd(sum + i, a[j]) == 1) flg = 1;
        if (flg) continue;
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << " " << i << '\n';
        return;
    }
}
*/
const int maxn = 30011;
void calc(int now, vector<int> v, int table[], int key, int key2) {
    rep3(i, now, maxn) {
        if (table[i] && i % 6 == key2) {
            v.eb(i);
            break;
        }
    }
    rep(i, sz(v)) {
        if (v[i] == key) continue;
        if (i) cout << " ";
        cout << v[i];
    }
    cout << '\n';
}

int main() {
    
    
    
    int table[maxn] = {0};
    int n;
    cin >> n;
    
    if (n <= 5) {
        if (n == 3) cout << "2 5 63" << '\n';
        else if (n == 4) cout << "2 5 20 63" << '\n';
        else // small();
            cout << "2 5 20 30 63" << '\n';
        return 0;
    }
    
    rep3(i, 2, maxn) {
        if (i % 6 == 2 || i % 6 == 3 || i % 6 == 4 || i % 6 == 0) {
            table[i] = 1;
        }
    }
    
    vector<int> v;
    int sum = 0;
    int now = 0, cnt = 0;
    rep(i, maxn) {
        if (table[i] == 1) {
            v.eb(i);
            sum += i;
            cnt++;
            if (cnt == n) { now = i + 1; break; }
        }
    }
    
    if (sum % 6 == 2) calc(now, v, table, 8, 0);
    else if (sum % 6 == 3) calc(now, v, table, 9, 0);
    else if (sum % 6 == 5) calc(now, v, table, 9, 4);
    else { // % 6 == 0
        rep(i, sz(v)) cout << v[i] << " "; cout << '\n';
    }
}
