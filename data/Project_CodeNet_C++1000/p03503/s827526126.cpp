#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
using Graph = vector<vector<int>>;
Graph G;

int main(){
    int n; cin >> n;
    vector<vector<int>> flag(n, vector<int>(10));
    rep(i, n)rep(j, 10) cin >> flag[i][j];

    vector<vector<ll>> p(n, vector<ll>(11));
    rep(i, n)rep(j, 11) cin >> p[i][j];
    
    ll ans = -10000000000;
    for(int bit = 0; bit < (1 << 10); bit++){
        vector<int> count(n, 0);
        ll sum = 0;
        bool chosed = false;

        rep(i, 10){
            if(bit & (1 << i)){
                chosed = true; 
                rep(j, n){
                    if(flag[j][i]) count[j]++;
                }
            }
        }
        rep(i, n) sum += p[i][count[i]];
        if(chosed) ans = max(ans, sum);
    }
    cout << ans << endl;
}