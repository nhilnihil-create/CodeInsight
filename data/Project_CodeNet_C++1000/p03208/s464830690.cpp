#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N ,K, ans = 1e11;
    cin >> N >> K;
    vector<ll> tree(N,0);
    for(int i = 0; i < N; i++) cin >> tree[i];
    sort(tree.begin(), tree.end());
    for(int i = 0; i < N; i++){
        if(i + (K - 1) == N) break;
        ans = min(ans, abs(tree[i + (K - 1)] - tree[i]));
    }
    cout << ans << endl;
}
