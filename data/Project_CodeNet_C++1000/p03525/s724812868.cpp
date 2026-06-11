#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int d[55];
int c[13]; // 時刻%12の個数をカウントする

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> d[i];
    c[0] = 1;
    rep(i, n) c[d[i]]++;

    vector<int> res;

    for(int bits = 0; bits < (1<<12); bits++){
        int tmp = 12;
        vector<int> v;
        v.push_back(24);
        if (c[0] >= 2) tmp = 0;
        else if (c[0] == 1) v.push_back(0);
        if (c[12] >= 2) tmp = 0;
        else if (c[12] == 1) v.push_back(12);

        for(int i = 1; i < 12; i++){
            if (c[i] >= 3) tmp = 0;
            else if (c[i] == 2) {
                v.push_back(i);
                v.push_back(24-i);
            }
            else if (c[i] == 1){
                if (bits&(1<<i)) v.push_back(24 - i);
                else v.push_back(i);
            }
        }
        sort(v.begin(), v.end());
        // for(auto e : v) cout << e << " ";
        // cout << endl;
        rep(i, v.size()-1) tmp = min(tmp, v[i+1]-v[i]);
        res.push_back(tmp);
    }

    cout << *max_element(res.begin(), res.end()) << endl;

    return 0;
}