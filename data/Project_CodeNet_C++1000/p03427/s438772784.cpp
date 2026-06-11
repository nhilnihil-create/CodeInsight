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
    string s;
    cin >> s;
    int ans = 0;
    int l = s.size();
    bool check = true;
    rep(i, l - 1) {
        if(s[i + 1] != '9') check = false;
    }
    ans = s[0] - '0' - 1 + 9 * (l - 1);
    if(check) ans++;

    cout << ans << endl;
    
    return 0;
}