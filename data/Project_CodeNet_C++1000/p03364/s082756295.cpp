#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    string S[N];
    rep(i, N) cin >> S[i];
    int cnt = 0;
    rep(i, N){
        bool able = true;
        rep(j, N)rep(k, N){
            int p = (j+i)%N, q = (k+i)%N;
            if(S[p][k] != S[q][j]) able = false;
        }
        if(able) cnt++;
    }
    cout << cnt*N << endl;
}
