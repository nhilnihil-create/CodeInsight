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
    cin>>n;
    map<ll,ll> mp;
    ll d,t;
    rep(i,n){
        cin>>d;
        mp[d]++;
    }
    cin>>m;
    rep(i,m){
        cin>>t;
        if(mp[t]>0) mp[t]--;
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}