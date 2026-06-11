
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll target=max(max(a,b),c);
    ll else1, else2;
    if(target == a){
        else1 = c; else2 = b;
    }
    if(target == b){
        else1 = a; else2 = c;
    }
    if(target == c){
        else1 = a; else2 = b;
    }

    rep(i,k){
        target *= 2;
    }
    cout << target + else1 + else2 << endl;
    return 0;


}