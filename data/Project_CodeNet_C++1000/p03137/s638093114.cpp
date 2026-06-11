#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n,m;
    cin >> n >> m;

    vector <int> x(m);
    rep(i,m) cin >> x[i];

    sort(all(x));

    if(n >= m){
        cout << 0 << endl;
        return 0;
    }

    vector <int> dec(m-1);
    rep(i,m-1) dec[i] = x[i+1] - x[i];

    sort(all(dec));
    reverse(all(dec));
    dec.erase(dec.begin(), dec.begin()+(n-1));

    int ans=0;
    for(int i=0; i<dec.size();i++){
        ans += dec[i];
    }

    cout << ans << endl;

}