#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;

int main(){
    cin >> n >> k;
    ll res=0;
    for(ll b=1;b<=n;b++){
        if(b<=k) continue;
        res+=(b-k)*(n/b)+max(n%b-k+1,0LL);
    }
    if(k==0) res-=n;
    cout << res << endl;
}
