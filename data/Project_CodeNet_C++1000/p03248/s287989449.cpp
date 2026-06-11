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
    string s;
    cin >> s;
    int N = s.size();
    vector<int> vec;
    bool able = true;
    if(s[0] == '0' || s[N-1] == '1') able = false;
    rep(i, N-1){
        if(s[i] != s[N-2-i]) able = false;
        if(s[i] == '1') vec.pb(i+1);
    }
    if(!able){
        cout << -1 << endl;
        exit(0);
    }
    vec.pb(N);
    int n = vec.size();
    rep(i, n-1){
        cout << vec[i] << ' ' << vec[i+1] << endl;
        rep2(j, vec[i]+1, vec[i+1]-1){
            cout << j << ' ' << vec[i+1] << endl;
        }
    }
}