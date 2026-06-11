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
    vector<int> odd, even;
    rep(i, 3) {
        int a;
        cin >> a;
        if(a % 2 == 0) even.push_back(a);
        else odd.push_back(a);
    } 
    int ans = 0;
    if(even.size() == 2) {
        ans++;
        rep(i, even.size()) even[i]++;
    }
    if(even.size() == 1) {
        ans++;
        rep(i, odd.size()) odd[i]++;
    }
    int maxv = -1;
    
  
    for(auto x : even) maxv = max(x, maxv);
    for(auto x : odd) maxv = max(x, maxv);
    for(auto x : even) ans += (maxv - x) / 2;
    for(auto x : odd) ans += (maxv - x) / 2;
    cout << ans << endl;
    return 0;
}