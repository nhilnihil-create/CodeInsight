#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    cin >> n;

    for(ll i=1; i<=3500; i++){
        for(ll j=1; j<=3500; j++){
            ll w1=4*i*j-n*i-n*j;
            if(w1<=0) continue;
            ll w2=n*i*j;
            // cout << w1 << ' ' << w2 << endl;
            if(w1==0) continue;
            if(w2%w1==0){
                cout << i << ' ' << j << ' ' << w2/w1 << endl;
                return 0;
            }
        }
    }

    return 0;
}