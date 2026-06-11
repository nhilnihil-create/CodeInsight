#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll x,y;
    cin >> x >> y;

    int n = 1;
    while(x>y || 2*x<=y){x += x; n++;}
    cout << n << endl;
}