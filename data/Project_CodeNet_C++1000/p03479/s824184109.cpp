#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl

ll x, y;
int main() {
    cin >> x >> y;
    int ans = 1;
    rep(i, x, y+1){
        x *= 2;
        if(x>y) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
