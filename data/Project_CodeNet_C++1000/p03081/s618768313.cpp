#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    s = '?' + s + '?';
    char t[Q], d[Q];
    rep(i, Q){
        cin >> t[i] >> d[i];
    }
    //lより左とrより右が最終的にはけられる
    int l = 0, r = N+1;
    rep3(i, Q-1, 0){
        if(t[i] == s[l+1] && d[i] == 'L') l++;
        elif(t[i] == s[l] && d[i] == 'R') l--;
        if(t[i] == s[r-1] && d[i] == 'R') r--;
        elif(t[i] == s[r] && d[i] == 'L') r++;
    }
    cout << r-l-1 << endl;
}