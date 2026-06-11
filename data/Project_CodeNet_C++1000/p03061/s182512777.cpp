#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_editorial
int main() {
    int n;cin>>n;
    int a[n];rep(i,n)cin>>a[i];
    int l[n],r[n];
    l[0]=a[0];
    r[n-1]=a[n-1];
    rep(i,n-1)l[i+1]=__gcd(l[i],a[i+1]);
    rep(i,n-1)r[n-2-i]=__gcd(r[n-1-i],a[n-2-i]);
    
    int ans = 1;
    rep(i,n-2)ans=max(ans,__gcd(l[i],r[i+2]));
    ans=max(ans,l[n-2]);
    ans=max(ans,r[1]);
    cout<<ans<<endl;
	return 0;
}