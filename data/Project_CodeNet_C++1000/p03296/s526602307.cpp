#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
const ll MOD=1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep (i,N){
        cin >> a[i];
    }
    int ans=0;
    rep (i,N-1){
        if (a[i]==a[i+1]){
            ans++;
            i++;
        }
    }
    cout << ans << endl;
}