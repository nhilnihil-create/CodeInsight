#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000000000000000
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    if(abs(a-b)>NUM){
        cout<<"Unfair";
        return 0;
    }
    if(k%2==0) cout<<a-b;
    else cout<<b-a;
}