#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n,m;
    cin >> n >> m;
    //vector<int> a(n), b(n);
    vector<pair<ll, int>> x(n);
    for(int i=0;i<n;i++) cin >> x[i].first >> x[i].second;
    
    sort(x.begin(), x.end());
    
    ll ans =0;
    for(int i=0;i<n;i++){
        if(m<=x[i].second){
            ans += m*x[i].first;
            break;
        }
        ans += x[i].first * x[i].second;
        m -= x[i].second;
    }
    
    cout << ans << endl;
    return 0;
}
