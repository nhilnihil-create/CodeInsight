#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0 && (n/i)-1 > i){
            ans += n/i - 1;
        } 
    }
    cout << ans << endl;
    return 0;
}