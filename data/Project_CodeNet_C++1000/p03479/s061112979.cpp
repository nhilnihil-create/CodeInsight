#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;

int main(){
    ll x,y;
    cin >> x >> y;
    int ans=0;
    while(1){
        if(x<=y) ans++;
        else break;
        x*=2;
    }
    cout << ans << endl;
}