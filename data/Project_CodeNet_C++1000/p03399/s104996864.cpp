#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int res, ans;
    res = min(a, b);
    ans = min(c, d);

    ans += res;
    cout << ans << endl;
}