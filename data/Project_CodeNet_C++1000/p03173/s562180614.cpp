#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);
const int MOD = 1000000007;

int N;
vector<ll> a(500);
bool seen[500][500];
ll memo[500][500];
ll sum[500];

// [l, r) のコストの最小値
ll rec(int l, int r){
    if(seen[l][r]) return memo[l][r];
    seen[l][r] = true;
    if(l==r) return 0;

    ll mi = INF;
    for(int i=l;i<r;i++){
        mi = min(mi, rec(l,i) + rec(i+1,r));
    }

    return memo[l][r] = mi+sum[r]-sum[l-1];
}

int main(){
    cin >> N;
    rep(i,N){
        cin >> a[i+1];
        sum[i+1] = sum[i] + a[i+1];
    }
    cout << rec(1,N) << endl;
}