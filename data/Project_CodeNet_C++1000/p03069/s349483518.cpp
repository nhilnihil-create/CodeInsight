#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> white(n, 0);
    vector<ll> white_sum(n + 1);
    vector<ll> black(n, 0);
    vector<ll> black_sum(n + 1);
    white_sum[0] = 0;
    black_sum[0] = 0;


    
    rep(i,n){
        if(s[i] == '.')white[i] = 1;
        if(s[i] == '#')black[i] = 1;
    }
    _rep(i, 1, n + 1){
        white_sum[i] = white[i - 1] + white_sum[i - 1];
        black_sum[i] = black[i - 1] + black_sum[i - 1];
    }
    //cout << white_sum[n] << " " << black_sum[n] << endl;

    ll ans_min = N;
    rep(i,n + 1){
        ll ans = ((n - i) - (white_sum[i] - white_sum[0])) + (i - (black_sum[n] - black_sum[i]));
        ans_min = min(ans, ans_min);
        //cout << ans << endl;
    }
    cout << ans_min << endl;
}