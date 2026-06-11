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
    int a[2][n],sum=0;
    rep(i,2){
        rep(j,n) cin>>a[i][j];
    }
    rep(i,n){
        int maxi=0;
        rep(j,n-i){
            maxi+=a[0][j];
        }
        repi(j,n-i-1,n){
            maxi+=a[1][j];
        }
        sum=max(maxi,sum);
    }
    cout<<sum;
}