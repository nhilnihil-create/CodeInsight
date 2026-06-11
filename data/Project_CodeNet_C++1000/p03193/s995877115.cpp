#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    ll n,h,w;
    cin >> n >> h >> w;
    ll a[n], b[n],ans=0;
    rep(i,n){
        cin >> a[i] >> b[i];
        if(a[i] >= h && b[i] >= w) ans++;
    }
    cout << ans << endl;
}
