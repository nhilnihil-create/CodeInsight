#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int a,b;
    cin >> a >> b;
    int defference = b - a;
    
    int west = 1;
    int east = 3;
    for(int i = 3; i <= 1000;i++){
        if(east - west == defference){
            cout << east - b << endl;
            break;
        }
        west = east;
        east += i;
    }
    
}

