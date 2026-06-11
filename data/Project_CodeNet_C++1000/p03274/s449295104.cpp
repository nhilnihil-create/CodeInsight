#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF = ll(1e18) +1;

int main() {
    ll N,K;
    cin >> N >>K ;
    vector<ll> x(N);
    for(int i=0;i<N;i++){
        cin >> x[i];
    }
    ll ans =INF;
    for(int i=K-1;i<N;i++){
        ll small = x[i+1-K];
        ll big = x[i];
        if(small <=0 && big<=0){
            ans = min(ans,abs(small));
        }
        if(small <=0 && big >0){
            ans = min(ans,min(abs(small)*2 +big,abs(small) + big*2));
        }
        if(small >0 && big >0){
            ans = min(ans,big);
        }
    }
    cout << ans << endl;

    return 0;
}