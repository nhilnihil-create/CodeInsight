#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    ll n; cin >> n;

    bool jud = true;
    ll ans = 0;
    ll modifier = 1002003004;

    rep(i,n){
        ll a, b; cin >> a >> b;
        if(a != b) jud = false;
        ans += a;

        if(a > b){
            modifier = min(modifier, b);
        }
        
    }

    if(jud) cout << 0 << endl;

    else{
        cout << ans - modifier << endl;
    }
    
}