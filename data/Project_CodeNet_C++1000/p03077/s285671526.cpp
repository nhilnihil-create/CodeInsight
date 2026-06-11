#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000000000010
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll n,a,mini=NUM;
    cin>>n;
    rep(i,5){
        cin>>a;
        if(a<mini) mini=a;
    }
    ll ans;
    if(n%mini==0) ans=n/mini+4;
    else ans=n/mini+5;
    cout<<ans<<endl;
}