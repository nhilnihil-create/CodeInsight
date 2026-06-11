#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

const ll mod = 1e9 + 7;

int main(){
    int n;
    string s;
    cin >> n >> s;
    map<char, int> mp;
    rep(i, n){
        mp[s[i]]++;
    }
    ll ans = 1;
    rep(i, mp.size()){
        if (mp[i] > 0){
            ans *= mp[i] + 1;
            ans %= mod;
        }
    }

    cout << ans - 1 << endl;
    return 0;
}