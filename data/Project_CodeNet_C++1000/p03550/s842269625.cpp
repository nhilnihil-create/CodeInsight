#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n,z,w;cin>>n>>z>>w;
    int a[n];
    rep(i,n)cin>>a[i];

    int ans = abs(a[n-1]-a[n-2]);
    ans = max(ans,abs(a[n-1]-w));
    if(n==1)ans = abs(a[0]-w);
    cout<<ans<<endl;
	return 0;
}
