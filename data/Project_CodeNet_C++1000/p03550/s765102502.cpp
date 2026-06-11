#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll N, Z, W;
vector<ll> a;

ll dfs(ll x, ll y, ll i, ll c){
    if(i == N-1){
        if(c%2 == 0) return abs(y-a[N-1]);
        else return abs(x-a[N-1]);
    }
    if(c%2 == 0){
        ll ret1 = dfs(a[i], y, i+1, c+1);
        ll ret2 = dfs(x, y, i+1, c);
        return max(ret1, ret2);
    }else{
        ll ret1 = dfs(x, a[i], i+1, c+1);
        ll ret2 = dfs(x, y, i+1, c);
        return min(ret1, ret2);
    }
}

int main(){
    cin >> N >> Z >> W;
    a.resize(N);
    rep(i, 0, N) cin >> a[i];

    if(N == 1) cout << abs(W-a[0]) << endl;
    else cout << max(abs(W-a[N-1]), abs(a[N-2] - a[N-1]));    
    return 0;
}