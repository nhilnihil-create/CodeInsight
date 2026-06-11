#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, M;
    cin >> N >> M;
    ll x[M];
    rep(i, M) cin >> x[i];
    ll ans;
    if(N >= M){
        ans = 0;
    }else{
        sort(x, x + M);
        ll sub[M];
        sub[0] = 0;
        for(int i = 1; i < M; i++) sub[i] = x[i] - x[i-1];
        sort(sub, sub + M, greater<ll>());
        ans = x[M-1] - x[0];
        rep(i, N-1) ans -= sub[i];
    }
    cout << ans << endl;
    return 0;
}