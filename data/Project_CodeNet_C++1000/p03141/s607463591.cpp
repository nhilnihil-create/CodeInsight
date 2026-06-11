#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    
    int n;
    cin>>n;
    
    ll a,b;
    
    vector<tuple<ll, ll, ll>> ab(n);
    
    for(int i=0; i<n; i++){
        cin >> a >> b;
        ab[i] = make_tuple(a+b, a, b);
    }
    
    sort(ab.rbegin(), ab.rend());
    
    ll ans = 0LL;
    
    for(int i=0; i<n; i++){
        if(i%2==0)
            ans += get<1>(ab[i]);
        else
            ans -= get<2>(ab[i]);
    }
    
    cout << ans << endl;
}