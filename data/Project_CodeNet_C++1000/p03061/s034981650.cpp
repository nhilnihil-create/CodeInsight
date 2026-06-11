#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];
    for(long long i=0;i<n;i++) cin >> a[i];
    long long l[n+1];
    l[0]=0;
    for(long long i=1;i<=n;i++){
        l[i]=__gcd(l[i-1],a[i-1]);
    }
    long long r[n+2];
    r[n+1]=0;
    for(long long i=n;i>0;i--){
        r[i]=__gcd(r[i+1],a[i-1]);
    }
    long long m[n+1];
    long long ans=0;
    for(long long i=1;i<=n;i++){
        m[i]=__gcd(l[i-1],r[i+1]);
        ans=max(ans,m[i]);
    }
    cout << ans << endl;
}
