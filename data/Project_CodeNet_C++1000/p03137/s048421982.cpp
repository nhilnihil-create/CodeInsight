#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    if(n>=m){
        cout << 0 << endl;
        return 0;
    }
    vector<int> x(m);
    rep(i,m) cin >> x[i];
    sort(x.begin(),x.end());
    vector<int> l(m-1);
    for(int i=1; i<m; i++){
        l[i-1] = x[i]-x[i-1];
    }
    sort(l.begin(),l.end());
    ll ans = 0;
    rep(i,m-n){
        ans += l[i];
    }
    cout << ans << endl;


    return 0;
}