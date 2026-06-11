#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    ll n,m,ans;
    cin>>n>>m;
    if (n==1&&m==1) ans=1;
    else if (n==1||m==1) ans=n*m-2;
    else ans=(n-2)*(m-2);
    cout<<ans<<endl;
} 
