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
    int n;
    cin>>n;
    if(n<105) cout<<0;
    else if(105<=n&&n<135) cout<<1;
    else if(135<=n&&n<165) cout<<2;
    else if(165<=n&&n<189) cout<<3;
    else if(189<=n&&n<195) cout<<4;
    else cout<<5;
}