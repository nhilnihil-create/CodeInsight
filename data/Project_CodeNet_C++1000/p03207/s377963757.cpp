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
    vector<int> p(n);
    int maxi = 0;
    rep(i,n){
        cin >> p[i];
        if(p[maxi] < p[i])maxi = i;
    }

    int ans = 0;
    rep(i,n){
        ans += (i != maxi ? p[i] : p[i]/2);
    }

    cout << ans << endl;

}