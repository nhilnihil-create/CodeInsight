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
    ll n,m; cin >> n >> m;
    cout << (ll)pow(2, m) * (n - m) * 100 + 1900 * m * (ll)pow(2, m);
    



    /*int n; cin >> n;
    string s; cin >> s;
    vector<int> white(n, 0);
    vector<int> white_sum(n + 1);
    vector<int> black(n, 0);
    vector<int> black_sum(n + 1);

    
    rep(i,n){
        if(s[i] == '.')white[i] = 1;
        if(s[i] == '#')black[i] = i;
    }
    _rep(i, 1, n + 1){
        white_sum[i] = white[i - 1] + white_sum[i - 1];
        black_sum[i] = black[i - 1] + black_sum[i - 1];
        cout << white_sum[i] << endl;
    }
    int ans_min = N;
    rep(i,n + 1){
        int ans = white_sum[n] - white_sum[i];
        ans_min = min(ans, ans_min);
    }
    cout << ans_min << endl;*/
}