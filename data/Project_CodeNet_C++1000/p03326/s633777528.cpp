#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n, m; cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i,n) cin >> x.at(i) >> y.at(i) >> z.at(i);

    vector<vector<ll>> sum(8, vector<ll>(n, 0));
    rep(i, 8){
        rep(j, n){
            if(i==0)sum.at(i).at(j) = x.at(j) + y.at(j)+z.at(j);
            if(i==1)sum.at(i).at(j) = -x.at(j) + y.at(j)+z.at(j);
            if(i==2)sum.at(i).at(j) = x.at(j) - y.at(j)+z.at(j);
            if(i==3)sum.at(i).at(j) = -x.at(j) - y.at(j)+z.at(j);
            if(i==4)sum.at(i).at(j) = x.at(j) - y.at(j) - z.at(j);
            if(i==5)sum.at(i).at(j) = x.at(j) + y.at(j) - z.at(j);
            if(i==6)sum.at(i).at(j) = -x.at(j) + y.at(j) - z.at(j);
            if(i==7)sum.at(i).at(j) = -x.at(j) - y.at(j) - z.at(j);
        }
    }


    rep(i, 8){
        sort(sum.at(i).rbegin(), sum.at(i).rend());
    }

    ll ans = 0;
    rep(i, 8){
        ll tmp = 0;
        rep(j, m) {
            tmp += sum.at(i).at(j); 
            dump(sum.at(i).at(j));
        }
        ans = max(tmp, ans);
    }

    cout << ans << endl;

    return 0;
}
