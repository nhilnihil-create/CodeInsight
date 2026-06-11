#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// #define debug(a) cout << "["; rep(i,a.size()) cout << a[i] << ", "; cout<<"]"<< endl;

const ll mod = 1000000007;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> Ss(m, vector<int>(0));
    vector<int> Ps(m);
    rep(mi,m){
        int k; cin >> k;
        rep(ki,k){
            int s; cin >> s;
            Ss.at(mi).push_back(s);
        }
    }
    rep(i,m) cin >> Ps.at(i);

    int ans = 0;
    rep(i, pow(2, (float)n)){
        bitset<10> bs(i);
        bool isAns = true;
        rep(mi, m){
            int cnt = 0;
            for(int si: Ss.at(mi)){
                if(bs.test(si-1)){
                    cnt++;
                }
            }
            if(cnt % 2 != Ps.at(mi)){
                isAns = false;
                break;
            }
        }
        if(isAns) ans++;
    }
    cout << ans << endl;
    return 0;
}