#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int GCD(int a,int b){
    if(b==0) return a;
    return GCD(b,a%b);
}
int main() {
    ll n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    bool ans=true;
    ll gcd=GCD(n,m);
    ll nn=n/gcd,mm=m/gcd;
    rep(i,gcd){
        if(s[nn*i]!=t[mm*i]){
            ans=false;
            break;
        }
    }
    ll res=(n/gcd)*m;
    if(ans) cout<<res;
    else cout<<-1;
}