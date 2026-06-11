#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    // input
    int n, k;
    cin >> n >> k;
    vector<int> vs(n);
    rep(i,n) cin >> vs[i];

    // solve
    ll ans = 0;
    rep(i,n){
        rep2(j,i,n+1){
            ll tmp = 0;
            if(n-(j-i) > k) continue;
            vector<int> temochi;
            rep(l,n){
                if(i <= l && l < j) continue;
                temochi.emplace_back(vs[l]);
            }
            sort(ALL(temochi));

            int rest = k - (n - (j - i));
            rep(l,rest){
                if(temochi.size() == 0) break;
                if(temochi[0] >= 0) break;
                temochi.erase(temochi.begin());
            }
            rep(l,temochi.size()) tmp += temochi[l];
            ans = max(ans, tmp);
        }
    }

    // output
    cout << ans << endl;

    return 0;
}