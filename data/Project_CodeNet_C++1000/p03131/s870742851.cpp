#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll k,a,b;
    cin >> k >> a >> b;
    //交換する意味なし
    if(b-a<=2){
        cout << 1+k << endl;
        return 0;
    }
    ll x = a;
    k -= a-1;
    x += (k/2) * (b-a) + k%2;
    cout << x << endl;
    return 0;
}

