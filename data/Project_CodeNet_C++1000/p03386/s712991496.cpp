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
    ll a,b,k;
    cin>>a>>b>>k;
    if(b-a<=2*k-1){
        for(ll i=a;i<=b;i++) cout<<i<<endl;
    }
    else{
        for(ll i=0;i<k;i++) cout<<a+i<<endl;
        for(ll i=k-1;i>=0;i--) cout<<b-i<<endl;
    }
}