#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    bool zero = false;
    int mi = INF;
    rep(i,n){
        cin >> a[i];
        mi = min(mi,abs(a[i]));
        if(a[i] < 0){
            sum++;
        }else if(a[i] == 0){
            zero = true;
        }
    }
    ll ans = 0;
    rep(i,n){
        ans += abs(a[i]);
    }
    if(!zero && sum % 2 == 1){
        ans -= mi*2;
    }
    cout << ans << endl;

    cout << endl;
    return 0;
}
