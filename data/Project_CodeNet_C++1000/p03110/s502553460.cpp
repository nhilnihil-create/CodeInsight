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
    ld x,jpy=0,btc=0;
    string s;
    rep(i,n){
        cin>>x>>s;
        if(s=="JPY") jpy+=x;
        else btc+=x;
    }
    cout<<fixed<<setprecision(8)<<jpy+btc*380000;
}