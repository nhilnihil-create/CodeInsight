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
    vector<ll> march(5);
    ll m=0,a=0,r=0,c=0,h=0;
    string s;
    rep(i,n){
        cin>>s;
        if(s[0]=='M') m++;
        if(s[0]=='A') a++;
        if(s[0]=='R') r++;
        if(s[0]=='C') c++;
        if(s[0]=='H') h++;
    }
    march[0]=m,march[1]=a,march[2]=r,march[3]=c,march[4]=h;
    ll ans=0;
    rep(i,3){
        repi(j,i+1,4){
            repi(k,j+1,5){
                ans+=march[i]*march[j]*march[k];
            }
        }
    }
    cout<<ans;
}