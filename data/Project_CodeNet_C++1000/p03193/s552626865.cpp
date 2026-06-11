#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n,h,w;
    cin >> n >> h >> w;
    int ans = 0;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        ans += (a>=h&&b>=w);
    }
    cout << ans << endl;
    return 0;
}