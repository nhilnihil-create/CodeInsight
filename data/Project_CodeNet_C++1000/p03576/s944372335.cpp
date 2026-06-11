#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

/*
下辺にどれ、上辺にどれ、を列挙,間の点をカウント、xをソートしてK幅の最小値

->N^3logN

->2500*2500
*/

int main() {

    int N, K; cin >> N >> K;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    
    ll res = 5e18;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int s = min(x[i],x[j]), t = max(x[i],x[j]);
            vector<ll> z = {};
            for (int k = 0; k < N; k++) {
                if (s <= x[k] && x[k] <= t) z.push_back(y[k]);
            }
            if (z.size() < K) continue;
            sort(z.begin(),z.end());
            for (int k = 0; k < z.size()-K+1; k++) {
                chmin(res, (t-s)*(z[k+K-1]-z[k]));
            }
            
        }
    }
    cout << res << endl;


}
