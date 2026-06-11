#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    ll d, n;
    cin >> d >> n;

    if((d == 2) && (d < 1000000)){
        if(n != 100){
            cout << 100 * 100 * n << endl;
        }
        else{
            cout << 1010000 << endl;
        }
    }
    else if(d == 1){
        if(n != 100){
            cout << 100 * n << endl;
        }
        else{
            cout << 10100 << endl;
        }
    }
    else{
        if(n != 100){
            cout << n << endl;
        }
        else{
            cout << 101 << endl;
        }
    }
    return 0;
}