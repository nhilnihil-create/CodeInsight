#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    sort(s.begin(), s.end());
    vector<int>v;
    v.push_back(1);
    rep(i, 1, n){
        if(s[i]==s[i-1])v.back()++;
        else v.push_back(1);
    }
    ll ans = 1;
    rep(i, 0, v.size()){
        ans *= (v[i]+1);
        ans %= mod;
        //cout << v[i] << endl;
    }
    cout << (ans+mod-1)%mod << endl;
}