#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF = 2e9
#define LINF = 1e18
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << "=" << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO")
#define Yes(n) cout << ((n) ? "Yes" : "No")
#define PI 3.141592653589793

int main(){
    char c[2][3];
    rep(i,2){
        rep(j,3)cin >> c[i][j];
    }

    YES(c[0][0] == c[1][2] && c[0][1] == c[1][1] && c[0][2] == c[1][0]) << endl;

}