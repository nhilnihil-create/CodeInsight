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

const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> ans(n);
    rep(i,n) cin >> b[i];
    rep(ni, n){
        bool hasAns = false;
        for(int i = b.size() - 1; i >= 0; i--){
            if(b[i] == i + 1){
                b.erase(b.begin() + i);
                ans[n - ni - 1] = i + 1;
                hasAns = true;
                break;
            }
        }
        if(!hasAns){
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i,n){
        cout << ans[i] << endl;
    }

    return 0;
}
