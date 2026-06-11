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
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 3)rep(j, 3) cin >> c[i][j];

    vector<int> a(3), b(3);
    a[0] = 0;
    b[0] = c[0][0];
    b[1] = c[0][1];
    b[2] = c[0][2];
    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];
    bool flag = true;
    rep(i, 3)rep(j, 3){
        if(c[i][j] != a[i] + b[j]) flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}