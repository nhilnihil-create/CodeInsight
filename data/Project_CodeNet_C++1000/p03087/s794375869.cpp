#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
//using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dh[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dw[8] = {1, -1, 0, 1, -1, 0, 1, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
using Edge = pair<int,int>;
using Graph = vector<vector<Edge>>;
Graph G;
  
/*------------------------------------------------------------------*/

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> l(n);
    vector<int> r(n);
    rep(i, q){
        cin >> l[i] >> r[i];
    }

    vector<int> AC(n);
    AC[0] = 0;
    rep(i, n - 1){
        if(s.substr(i, 2) == "AC"){
            AC[i + 1] = 1;
        }
    }
    vector<int> AC_sum(n + 1);
    AC_sum[0] = 0;
    _rep(i, 1, n + 1){
        AC_sum[i] = AC_sum[i - 1] + AC[i - 1];
    }
    rep(i, q){
        cout << AC_sum[r[i]] - AC_sum[l[i]] << endl;
    }


}
