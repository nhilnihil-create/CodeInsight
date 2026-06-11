#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


bool path[101][101];

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    if (n%2 == 1){
        for(int i = 1; i <= n/2; i++){
            path[i][n-i] = 1;
            cnt++;
        }
    }
    else{
        for(int i = 1; i <= n/2; i++){
            path[i][n-i+1] = 1;
            cnt++;
        }        
    }

    
    cout << n*(n-1)/2 - cnt << endl;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++) if(!path[i][j]) cout << i << " " << j << endl;
    }

    return 0;
}
