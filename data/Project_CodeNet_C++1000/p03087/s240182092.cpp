#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define resort(v) sort((v).rbegin(), (v).rend())
#define vi vector<int>
#define vvi vector<vector<int>>
using ll = long long;
using P = pair<int, int>;
/* ------------------------------------------------ */
ll fact(int i) {       //階乗(i <= 20 まで)
    if (i == 0) return 1;
    return (fact(i - 1)) * i;
}
ll gcd(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a * b / gcd(a, b);
}
int keta(ll n) {        //桁数を求める
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/* ------------------------------------------------ */

int main() {
    int n,q;cin >> n >> q;
    string s;
    cin >> s;
    vi ans(n-1);
    rep(i, n-1) {
        if(s[i]=='A'&&s[i+1]=='C') {
            ans[i]++;
            i++;
        }
    }
    // for(auto p:ans) cout << p << ' '; // 確認済
    vi rui(n);
    rui[0] = 0;
    rep1(i,n-1) rui[i] += rui[i-1]+ans[i-1];
    // for(auto p:rui) cout << p << ' '; // 確認済
    // cout << endl;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        cout << rui[b-1] - rui[a-1] << endl;
    }
    return 0;
}