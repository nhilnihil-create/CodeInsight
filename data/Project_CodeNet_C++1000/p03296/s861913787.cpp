#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <iomanip>
#include <queue>
#include <cmath>

using namespace std;
using ll = long long;
using pa = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const long double EPS = 1e-11;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (int i = (l); i < (r); i++)
#define reper(i, l, r) for (int i = (r)-1; i >= (l); i--)

void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N;
    cin>>N;
    vl A(N);
    rep(i,N)cin>>A[i];
    ll ans=0;
    ll cnt =0,c=A[0];
    rep(i,N){
    	if(c==A[i])cnt++;
    	else{
    		ans+=cnt/2;
    		c=A[i];
    		cnt=1;
    	}
    }
    ans+=cnt/2;
    
    cout<<ans<<endl;
    return 0;
}
