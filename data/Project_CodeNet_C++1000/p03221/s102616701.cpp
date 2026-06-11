#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<P> a;
    rep(i, m){
        int x, y;
        cin >> x >> y;
        a.push_back(P(x, y));
    }
    vector<P> memo = a;
    sort(memo.begin(), memo.end());
    map<P, int> b;
    b[memo[0]] = 1;
    for(int i = 1; i < m; i++){
        if(memo[i-1].first == memo[i].first){
            b[memo[i]] = b[memo[i-1]] + 1;
        }else{
            b[memo[i]] = 1;
        }
    }
    rep(i, m){
        printf("%06d%06d\n", a[i].first, b[a[i]]);
    }
    return 0;
}