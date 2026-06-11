#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll n, ans = 1;
    string s;
    cin >> n >> s;
    vector<int> cnt(26, 0);
    rep(i, s.size())cnt[s[i]-'a']++;
    rep(i, 26)ans = ans * (cnt[i]+1) % mod; 
    cout << ans - 1 << endl;
}   