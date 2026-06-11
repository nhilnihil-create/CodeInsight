#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;
    cout << (a - b + 1) * (a - c + 1) << '\n';
    return 0;
}
