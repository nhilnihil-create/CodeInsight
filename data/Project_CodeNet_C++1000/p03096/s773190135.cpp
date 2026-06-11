#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;




int main()
{
    const ll mod = 1000000007;
    int N;
    cin >> N;
    vector<int> C;
    rep(i,N){
        int c;
        cin >> c;
        if(i == 0) C.push_back(c);
        else if(C.back() == c) continue;
        else C.push_back(c);
    }
    vector<ll> V(200005, 0);
    
    ll ans = 1;
    
    for (int i = 0; i < int(C.size()); i++) {
        
        if(V[C[i]] > 0) ans += V[C[i]];
        ans %= mod;
        V[C[i]] = ans;
        
    }
    
    cout << ans << endl;
    
    
    return 0;
}

