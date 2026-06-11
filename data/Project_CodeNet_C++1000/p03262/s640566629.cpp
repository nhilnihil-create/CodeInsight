#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,X;
    cin >> N >> X;
    vector<int> x(N+1);
    rep(i,N) cin >> x[i];
    x[N]=X;
    sort(x.begin(),x.end());
    // 差分の最大公約数
    int ans = x[1]-x[0];
    for(int i=1;i<=N;i++){
        ans = __gcd(x[i]-x[i-1],ans);
    }
    
    cout << ans << endl;
    return 0;
}