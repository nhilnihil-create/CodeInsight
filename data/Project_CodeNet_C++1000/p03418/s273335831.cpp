#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF=(1LL<<61)-1;


int main(){
    int n,k; cin >> n >> k;
    ll res = 0;
    for(int i=k+1;i<=n;i++){
        res += max(0, (n%i)-k+1);
        res += (n/i)*(i-k);
    }
    if(k==0) res -= n;
    cout << res << endl;
}