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
    int k[m],s[m][20];
    rep(i,m){
        cin>>k[i];
        rep(j,k[i]){
            cin>>s[i][j];
            s[i][j]--;
        }
    }
    int p[m];
    rep(i,m) cin>>p[i];
    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        int a=0;
        rep(i,m){
            int cnt=0;
            rep(j,k[i]) if(bit&(1<<s[i][j])) cnt++;
            if(cnt%2==p[i]) a++;
        }
        if(a==m) ans++;
    }
    cout<<ans;
}