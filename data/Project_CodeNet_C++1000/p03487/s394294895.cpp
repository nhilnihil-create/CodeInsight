#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n;
    cin >> n;
    map<ll,ll> hairetu;
    int ans=0;
    rep(i,n){
        int a;
        cin >> a;
        hairetu[a]++;
    }
    for(auto c:hairetu){
        int a,b;
        a = c.first; b=c.second;
        if(b<a) ans+=b;
        else ans += b-a;
    }
    cout << ans << endl;
}