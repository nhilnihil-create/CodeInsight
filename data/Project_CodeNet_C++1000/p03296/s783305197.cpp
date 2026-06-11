#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5+5;
typedef long long ll;
const ll INF = 1e4;
ll n, X, x[max_n]; 
void solve(){
    ll ans = 0;
    for(int i=0 ; i+1<n ; i++){
        if(x[i] == x[i+1]){
            x[i+1] = INF;
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> x[i];
    }
    solve();
    return 0;
}