#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;
    ll m = min(a,min(b,min(c,min(d,e))));
    
    ll ans;

    if (n%m==0) {
        ans = n/m-1+5;
    }
    else {
        ans = n/m+5;
    }
    cout << ans << endl;
}
