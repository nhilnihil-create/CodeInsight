#include<bits/stdc++.h>                                                                                               

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;j<=(n);++i)
#define all(x) (x).begin(),(x).end()
//#define int long long
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
signed main(){
    int a,b;
    cin >> a >> b;
    if(a % b == 0) cout << -1 << '\n';
    else cout << a << '\n';
    return 0;
}
