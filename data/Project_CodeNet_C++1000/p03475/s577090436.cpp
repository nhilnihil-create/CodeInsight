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
    int n; cin >> n;
    vector<int> c(n - 1);
    vector<int> s(n - 1);
    vector<int> f(n - 1);
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
    _rep(i, 1, n){
        vector<int> time(n, 0);
        _rep(j, i, n){
            int t = max(time[j - 1], s[j - 1]);
            time[j] = (t + f[j - 1] - 1) / f[j - 1] * f[j - 1] + c[j - 1]; 
        }
        cout << time[n - 1] << endl;
    }
    cout << 0 << endl;
}