#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    ll h, w, p;
    h = 0;
    w = 0;
    p = 0;

    for(int i = 1; i <= 3500; i++){
        for(int j = i; j <= 3500; j++){
            ll k = n * i * j;
            ll t = 4 * i * j - n * (i + j);
            if(t > 0){
                if(k % t == 0){
                    h = i;
                    w = j;
                    p = k / t;
                    break;
                }
            }
        }

        if(h != 0){
            break;
        }
    }

    cout << h << " " << w << " " << p << endl;
}