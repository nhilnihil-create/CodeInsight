#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    string s[3];
    rep(i,3)cin >> s[i];
    int ans = 0;
    rep(i,n){
        if(s[0][i]==s[1][i]&& s[1][i]==s[2][i])continue;
        else if(s[0][i]==s[1][i])ans++;
        else if(s[1][i]==s[2][i])ans++;
        else if(s[2][i]==s[0][i])ans++;
        else ans += 2;
    }
    cout << ans << endl;
}