#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000010
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,minus=0;
    bool zero=false;
    cin>>n;
    ll sum=0,mini=NUM;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        mini=min(mini,abs(a[i]));
        if(a[i]<0) minus++;
        if(a[i]==0) zero=true;
        sum+=abs(a[i]);
    }
    if(minus%2==1&&!zero) sum-=2*mini;
    cout<<sum<<endl;
}