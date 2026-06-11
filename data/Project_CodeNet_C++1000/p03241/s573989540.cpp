#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, M, ans=0, tmp=0;
vector<ll> A(MAXN, 0);

void yakusuu() {
    for(int i=1;i*i<=M;i++) {
        if(M%i==0&&i*N<=M) ans = max(ans, i);
        if(M%i==0&&M/i*N<=M) ans = max(M/i, ans);
    }
}

signed main(){
    cin >> N >> M;
    yakusuu();
    cout << ans << endl;
    return 0;
}