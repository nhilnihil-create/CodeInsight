#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    if(abs(c-1) > 1e18){
        cout << "Unfair" << endl;
        return 0;
    }

    if(k % 2 == 1){
        cout << b-a << endl;
    }else{
        cout << a-b << endl;
    }
    return 0;
}