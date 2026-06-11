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
    int n,m,k,fav,ans=0; cin>>n>>m;
    vector<int> food(m);
    rep(i,m) food[i]=0;
    rep(i,n){
        cin>>k;
        rep(j,k){
            cin>>fav;
            food[fav-1]++;
        }
    }
    rep(i,m){
        if(food[i]==n) ans++;
    }
    cout<<ans;
}