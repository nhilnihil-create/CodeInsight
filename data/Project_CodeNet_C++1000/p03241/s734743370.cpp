#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 100010;
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
/*------------------------------------------------------------------*/
int main(){
    int n, m; cin >> n >> m;

    if(m % n == 0){
        cout << m / n << endl;
        return 0;
    }

    int i = 1;
    int ans = -1;
    while(true){
        if(m % i == 0){
            if(i * n <= m) ans = i;
        } 
        if(i * n > m) break;
        i++;
    }
    cout << ans << endl;
}