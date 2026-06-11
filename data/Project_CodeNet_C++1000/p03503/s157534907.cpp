#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

int main(){
    int n;  cin >> n;
    vector<vector<ll>> g(n, vector<ll>(10)), p(n, vector<ll>(11));
    vector<ll> cnt(n, 0LL);
    for(int i=0; i<n; i++)
        for(int j=0; j<10; j++) cin >> g.at(i).at(j);

    for(int i=0; i<n; i++)
        for(int j=0; j<=10; j++) cin >> p.at(i).at(j);
    
    ll ans = -1e+15;
    for(int bit=1; bit<(1<<10); bit++){
        ll sum=0;
        for(int i=0; i<n; i++){
            int chk=0;
            for(int j=0; j<10; j++)
                if(bit&1<<j && g[i][j])    chk += 1; 
                
            sum += p[i][chk];
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;

}