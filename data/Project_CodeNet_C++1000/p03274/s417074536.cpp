#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
    int n,k; cin>>n>>k;
    vector<int> x(n);
    rep(i,0,n) cin>>x[i];
    int ans=INF;
    for(int i=0; i+k-1<n; i++){
        ans=min(ans,min(abs(x[i])+abs(x[i]-x[i+k-1]),abs(x[i+k-1])+abs(x[i]-x[i+k-1])));
    }
    cout<<ans<<endl;
}