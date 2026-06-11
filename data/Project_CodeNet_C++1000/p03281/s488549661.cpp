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
    
    int n;
    cin >> n;

    int ans = 0;

    for(int i = 1; i <= n; i+=2){
        int cnt = 0;
        for(int j = 1; j <= n; ++j){
            if(i%j == 0)cnt++;
        }
        if(cnt == 8)ans++;
    }

    cout << ans << endl;

}