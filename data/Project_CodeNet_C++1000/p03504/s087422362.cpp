#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
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

/*------------------------------------------------------------------*/


int main(){
    int n, c; cin >> n >> c;
    vector<vector<int>> imos(30, vector<int>(100001));
    rep(i, 30)rep(j, 100001) imos[i][j] = 0;
    rep(i, n){
        int d, e, f; cin >> d >> e >> f;
        d--, f--;
        imos[f][d]++, imos[f][e]--;
    }
    
    rep(i, c)_rep(j, 1, 100001) imos[i][j] += imos[i][j - 1];
    rep(i, c)rep(j, 100001){
        if(imos[i][j] > 0) imos[i][j] = 1;
    }

    int ans = 0;
    rep(i, 100001){
        int count = 0;
        rep(j, c){
            count += imos[j][i];
        }
        ans = max(count, ans);
    }
    cout << ans << endl;
}