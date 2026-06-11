#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000

int main() {
    int64_t n,k;
    cin >> n >> k;
    vector<int64_t> H(n);
    rep(i,n){
        cin >> H.at(i);
    }
    sort(H.begin(),H.end());
    int64_t ans = INF;
    rep(i,n-k+1){
        ans = min(ans,H.at(i+k-1)-H.at(i));
    }
    cout << ans << endl;
}