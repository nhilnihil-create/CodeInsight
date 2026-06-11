/*
      author : nishi5451
      created: 11.08.2020 23:31:38
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

ll GCD(ll x,ll y){
    if(x%y == 0) return y;
    else return GCD(y, x%y);
}

int main(){
    ll x,y;
    cin >> x >> y;
    if(x%y==0) {
        cout << -1 << endl;
        return 0;
    }
    cout << x << endl;

    return 0;
}