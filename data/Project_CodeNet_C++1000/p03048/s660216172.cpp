#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
using pll = pair<ll,ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;

int main(){
    int R,G,B,n;
    cin >> R >> G >> B >> n;
    int ans = 0;
    for(int i=0;i*R<=n;i++){
        for(int j=0;j*G<=n;j++){
            if( n - R*i - j*G < 0) continue;
            if((n-R*i-j*G)%B == 0) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}