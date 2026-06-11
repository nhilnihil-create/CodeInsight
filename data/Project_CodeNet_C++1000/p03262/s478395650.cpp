#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main() {
    long n,x;
    cin>>n>>x;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
        a[i]=abs(x-a[i]);
    }
    int ans=0;
    rep(i,n){
        ans=gcd(ans,a[i]);
    }
    cout<<ans;
}