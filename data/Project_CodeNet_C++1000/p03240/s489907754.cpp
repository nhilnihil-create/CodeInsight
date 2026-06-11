#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll x[n],y[n],h[n];
    for(int i = 0; i < n; i++){
        ll temp1,temp2,temp3;
        cin >> temp1 >> temp2 >> temp3;
        x[i] = temp1;
        y[i] = temp2;
        h[i] = temp3;
    }
    ll cx,cy,hh;
    bool hoge = false;
    ll ansx,ansy,ansh;
    for(int i = h[0]; i < h[0]+401; i++){
        for(int j = 0; j < 101; j++){
            for(int k = 0; k < 101; k++){
                bool ok = true;
              cx = j;
              cy = k;
              hh = i;
                for(int l = 0; l < n; l++){
                    ll height = max(0,(int)(hh-(int)abs(cx-x[l])-(int)abs(cy-y[l])));
                    if(height != h[l]) ok = false;
                  //break;
                }
                if(ok){
                    ansx = j;
                    ansy = k;
                    ansh = i;
                    //break;
                }
            }
        }
    }
    cout << ansx << " " << ansy << " " << ansh;
}

