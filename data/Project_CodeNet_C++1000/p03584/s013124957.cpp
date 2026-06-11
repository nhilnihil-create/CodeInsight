#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int ll;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    ll ans = 0;
    for(int i = 0; i <= 30; i++){
        if(i != 0 && (k & (1LL << i)) == 0) continue;
        ll t;
        if(i == 0) t = k;
        else t = k & ~(1LL << i) | ((1LL << i) - 1);
        ll sum = 0;
        for(int j = 0; j < n; j++){
            if((t | a[j]) == t) sum += b[j]; 
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
