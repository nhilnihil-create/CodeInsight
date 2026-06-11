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
    vector<int> x(n), y(n);
    rep(i, n){
        cin >> x[i];
        y[i] = x[i];
    }
    sort(y.begin(), y.end());
    rep(i, n){
        if(x[i] < y[n / 2]) cout << y[n / 2] << endl;
        else cout << y[n / 2 - 1] << endl; 
    }
}