#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

ll d(ll x) {
    ll res=0;
    while(x) { 
        res+=x%10; 
        x/=10;
    }
    return res;
}

int main() {
    int n,res,ans=10000000;
    cin>>n;
    for (int a=1; a<=n-1; a++) {
        int b=n-a;
        res=d(a)+d(b);
        ans=min(ans,res);
    }
    cout<<ans<<endl;
}
