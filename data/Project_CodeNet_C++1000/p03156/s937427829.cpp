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

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/

int main(){
    int n; cin >> n;
    int a, b; cin >> a >> b;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    int a_count = 0;
    int b_count = 0;
    int c_count = 0;

    rep(i, n){
        if(p[i] <= a)a_count++;
        else if(a < p[i] && p[i] <= b)b_count++;
        else c_count++;
    }
    cout << min({a_count, b_count, c_count}) << endl;

}