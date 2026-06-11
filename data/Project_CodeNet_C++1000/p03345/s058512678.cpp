#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    ll t = a - b;

    if(abs(t) > 10e17){
        cout << "Unfair" << endl;
    }else{
        if(k % 2 == 0){
            cout << t << endl;
        }else{
            cout << 0 - t << endl;
        }
    }
}