#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,d;
    cin>>d>>n;
    int ans;
    if(d==0) ans=n;
    else if(d==1) ans=n*100;
    else if(d==2) ans=n*10000;
    if(n==100) ans+=ans/100;
    cout<<ans;
}