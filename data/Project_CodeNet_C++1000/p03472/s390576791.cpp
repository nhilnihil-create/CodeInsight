#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
const ll inf = 1001001001;

int main(){
    int n;
    ll h;
    cin >> n >> h;
    vector<ll>a(n);
    vector<ll>b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    int cnt = 0;
    ll damage = 0;
    rep(i, 0, n){
        if(a[0] > b[i])break;
        damage += b[i];
        cnt++;
        if(damage >= h)break;
    }
    if(damage >= h){
        cout << cnt << endl;
    }
    else if((h-damage)%a[0] == 0)cout << cnt + (h-damage)/a[0] << endl;
    else{
            cout << cnt + ((h-damage)/a[0]) +1 << endl;
        }
}