#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod %
using namespace std;
using ll = long long;
using P = pair<int,int>;

//pdf見て回答

int main(){
    ll a, b, c, k; cin >> a >> b >> c >>k;
    ll x, y, z;
    
    if(k mod 2 == 0){
        cout << a - b << endl;
    }else{
        cout << b - a << endl;
    }


    /*
    rep(i,k){
        x = b + c;
        y = a + c;
        z = a + b;

        a = x; b = y; c = z;
    }

    if(abs(a - b) < 1e18){
        cout << a - b;
    }else{
        cout << "Unfair";
    }
    cout << endl;
    */
}