/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+5;

int a , b , c , d;

int main(){
    cin >> a >> b >> c >> d;
    if(a + b < c + d){
        cout << "Right";
    } else if(a + b == c + d){
        cout << "Balanced";
    } else {
        cout << "Left";
    }

}



