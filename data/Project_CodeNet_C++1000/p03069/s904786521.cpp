#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> w(n);
    vector<int> b(n);
    rep(i, n){
        if(s[i] == '.'){
            w[i] = 1, b[i] = 0;
        }else{
            w[i] = 0, b[i] = 1;
        }
    }
    vector<int> w_sum(n + 1);
    vector<int> b_sum(n + 1);

    b_sum[0] = 0, w_sum[0] = 0;
    rep(i, n + 1){
        w_sum[i] = w_sum[i - 1] + w[i - 1];
        b_sum[i] = b_sum[i - 1] + b[i - 1];
    }
    int ans;
    int ans_min = INFINITY;
    _rep(i, 1, n + 1){
        ans = b_sum[i - 1] + (w_sum[n] - w_sum[i]);
        ans_min = min(ans, ans_min);
    }
    cout << ans_min << endl;
}
