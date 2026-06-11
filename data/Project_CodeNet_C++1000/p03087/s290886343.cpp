#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<ll> csum(n, 0);
    csum[0] = 0;
    rrep(i, n - 1) {
        csum[i] += csum[i - 1];
        if(s[i - 1] == 'A' && s[i] == 'C') csum[i]++;
    }
    
    vector<ll> ans(q);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        ans[i] = csum[r] - csum[l];
    }
    for(auto x : ans) cout << x << endl;
    
    return 0;
}