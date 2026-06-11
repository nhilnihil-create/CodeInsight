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
    vector<ll> x(n),y(n);
    rep(i,n){
        cin>>x[i];
        y[i]=x[i];
    }
    sort(all(y));
    rep(i,n){
        if(x[i]<y[n/2]) cout<<y[n/2]<<" ";
        else cout<<y[n/2-1]<<" ";
    }
}