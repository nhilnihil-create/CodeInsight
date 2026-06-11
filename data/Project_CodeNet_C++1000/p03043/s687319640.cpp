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
    ld n,k;
    cin>>n>>k;
    ld ans=0;
    repi(i,1,n+1){
        ld dice=1.0/n,points=i;
        while(points<k){
            points*=2;
            dice/=2;
        }
        ans+=dice;
    }
    cout<<setprecision(10)<<ans;
}