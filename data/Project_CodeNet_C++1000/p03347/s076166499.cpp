#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    
    if(a[0] != 0){ cout << -1 << endl; return 0; }

    ll ans = 0;
    ll save = 0;
    bool check = true;
    loop(i,1,n){
        if(a[i] == 0){ ans += save; save = 0; }
        else if(a[i] == save + 1){ save++; }
        else if(a[i] < save + 1){ ans += save; save = a[i]; }
        else if(a[i] > save + 1){ check = false; break; }
    }
    ans += save;
    if(check) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}