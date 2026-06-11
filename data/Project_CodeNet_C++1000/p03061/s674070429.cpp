#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int nax = 1e7+7;
const int MOD = 1e9+7;

int main(){
    int n; cin>>n;

    int v[n];

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    vector<int> f(n), r(n);

    f[0] = v[0];
    r[n-1] = v[n-1];

    for(int i=1; i<n; i++){
        f[i] = __gcd(f[i-1], v[i]);
    }

    for(int i=n-2; i>=0; i--){
        r[i] = __gcd(r[i+1], v[i]);
    }

    int ans = max(f[n-2], r[1]);
    for(int i=1; i<n-1; i++){
        ans = max(ans, __gcd(f[i-1], r[i+1]));
    }

    cout<<ans<<endl;
    
    return 0;
}