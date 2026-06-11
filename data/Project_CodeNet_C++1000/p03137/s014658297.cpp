#include<bits/stdc++.h>
/* #define int long long */
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

signed main(){
    int n, m;
    cin >> n >> m;
    vi x(m);
    vi diff(m-1);
    rep(i, m) cin >> x[i];
    sort(x.begin(), x.end());

    if(n >= m){
        cout << 0 << endl;
        return 0;
    }


    rep(i, m-1){
        diff[i] = x[i+1] - x[i];
    }
    sort(diff.begin(), diff.end(), greater<int>());

    int ans = *(x.end()-1) - *x.begin();

    rep(i, n-1){
       /*  cout << "diff = " << diff[i] << " "; */
        ans -= diff[i];
    }
    cout << ans << endl;
}