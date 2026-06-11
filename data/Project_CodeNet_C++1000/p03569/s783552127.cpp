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
template <typename T>
inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>
inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    string s, t;
    cin >> s;
    rep(i, s.size()){
        if (s[i] != 'x')
            t.push_back(s[i]);
    }

    rep(i, t.size()){
        if (t[i] != t[t.size() - 1 - i]){
            cout << -1 << endl;
            return 0;
        }
    }

    ll bl = 0, ans = 0;
    vector<ll> block;

    rep(i, s.size()){
        if (s[i] == 'x'){
            bl++;
        }
        else{
            block.push_back(bl);
            bl = 0;
        }

        if (i == (ll)(s.size() - 1))
            block.push_back(bl);
    }

    /*rep(i,block.size()){
        cout<<block[i]<<endl;
    }*/

    rep(i, block.size() / 2){
        ans += abs(block[i] - block[block.size() - 1 - i]);
    }

    cout << ans << endl;
    return 0;
}