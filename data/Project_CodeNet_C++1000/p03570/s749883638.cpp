#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

string s;
int a[200010];
int dp[1 << 26];
int ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 1; i < (1 << 26); i++) dp[i] = inf;
    for(int i = 0; i < s.length(); i++){
        a[i] ^= 1 << (s[i] - 'a');
        a[i + 1] = a[i];
    }
    for(int i = 0; i < s.length(); i++){
        int opt = dp[a[i]];
        for(int j = 0; j < 26; j++){
            int to = (1 << j) ^ a[i];
            if(dp[to] < opt) opt = dp[to];
            
        }
        chmin(dp[a[i]], opt + 1);
        if(i == s.length() - 1) ans = opt + 1;
    }
    cout << ans << endl;
    return 0;
}