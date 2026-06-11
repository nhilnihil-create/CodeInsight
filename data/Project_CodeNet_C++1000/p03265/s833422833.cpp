#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll x1, x2, y1, y2, x3, y3 ,x4 ,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    
    x4 = (x2 - x1) * 0 - (y2 - y1) * 1 + x1;
    y4 = (x2 - x1) * 1 + (y2 - y1) * 0 + y1;

    x3 = (x1 - x2) * 0 - (y1 - y2) * -1 + x2;
    y3 = (x1 - x2) * -1 + (y1 - y2) * 0 + y2;


    cout << x3 <<" "<< y3 <<" "<< x4 <<" "<< y4 << endl; 



}