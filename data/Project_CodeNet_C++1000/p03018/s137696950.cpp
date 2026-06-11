#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

vector<vector<int>> a;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;

    while(i < n){
        vector<int> tmp;
        while (true){
            if(s[i] == 'A') tmp.push_back(1), i++;
            else if (i < n-1 && s[i] == 'B' && s[i+1] == 'C') tmp.push_back(0), i+=2;
            else{
                i++;
                break;
            }
        }
        if (!tmp.empty()) a.push_back(tmp);
    }

    ll m = a.size();
    ll ans = 0;
    rep(i, m){
        ll cnt = 0, dist = 0;
        rep(j, a[i].size()){
            if (a[i][j] == 0) cnt++, dist += j;
        }
        if (cnt < a[i].size()) ans += dist - cnt * (cnt - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}