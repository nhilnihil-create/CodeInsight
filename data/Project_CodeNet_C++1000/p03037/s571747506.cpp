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
    int n,m;
    cin>>n>>m;
    int ll=0,rr=100010,l,r;
    rep(i,m){
        cin>>l>>r;
        ll=max(ll,l);
        rr=min(rr,r);
    }
    if(rr-ll+1<=0){
        cout<<0; return 0;
    }
    cout<<rr-ll+1;
}