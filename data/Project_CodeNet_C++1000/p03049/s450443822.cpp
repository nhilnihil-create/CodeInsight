#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll n, ans = 0;
    cin >> n;
    vector<string> s(n);
    ll front_b = 0, back_a = 0, ab = 0;
    
    rep(i, n){
        cin >> s[i];
        ll num = s[i].size();
        if (s[i][0] == 'B' && s[i][num - 1] == 'A')
            ab++;
        else if (s[i][0] == 'B')
            front_b++;
        else if (s[i][num - 1] == 'A')
            back_a++;
    }

    ans += max(0ll, ab - 1);
    if (ab >= 1)
        ab = 1;

    if(!(front_b==0 && back_a==0)){
        if (front_b >= back_a){
            ans += (back_a + ab);
        }else{
            ans += (front_b + ab);
        }
    }

    rep(i, n){
        rep(j, s[i].size() - 1){
            if (s[i][j] == 'A' && s[i][j + 1] == 'B')
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}