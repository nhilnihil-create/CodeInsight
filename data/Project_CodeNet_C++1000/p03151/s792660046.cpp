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
    vector<ll> a(n),b(n),c;
    ll suma=0,sumb=0;
    rep(i,n){
        cin>>a[i];
        suma+=a[i];
    }
    ll cnt1=0,cnt2=0,s=0;
    rep(i,n){
        cin>>b[i];
        if(a[i]<b[i]){
            cnt1++;
            s+=b[i]-a[i];
        }
        else if(a[i]>b[i]) c.push_back(a[i]-b[i]);
        sumb+=b[i];
    }
    sort(all(c));
    int i=c.size()-1;
    while(s>0){
        s-=c[i];
        cnt2++;
        i--;
    }
    if(suma<sumb) cout<<-1;
    else cout<<cnt1+cnt2;
}