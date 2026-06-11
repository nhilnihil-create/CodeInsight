#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int (i) = (a);(i) < (b);i++)
#define Rep(i,n) For((i),0,(n))
#define All(a) (a).begin(),(a).end()
#define sp " "
#define INF 1e9
#define F first
#define S second


const int MAX = 402;

typedef long long ll;
const ll MOD = 1000000007;
const ll MOD_9 = 998244353;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    Rep(i,n)cin >> a[i];
    if(a[0] != 0){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    Rep(i,n){
        if(a[i+1] - a[i] > 1){
            cout << -1 << endl;
            return 0;
        }else if(a[i+1] - a[i] != 1){
            ans += a[i];
        }
    }
    cout << ans << endl;
    //cin >> n;
}