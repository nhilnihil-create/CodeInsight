#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int mass = (a+b)-(c+d);
    if(mass == 0){
        cout << "Balanced";
    }else if(mass > 0){
        cout << "Left";
    }else{
        cout << "Right";
    }
    return 0;
}