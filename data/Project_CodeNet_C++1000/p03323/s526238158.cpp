#include <bits/stdc++.h> 
using namespace std; 

int main() {
    int a, b; 
    cin >> a >> b;

    // if (a == b) cout << "Yay!";
    // else {
    //     if (a > b) {
    //         if (b >= a / 2) cout << "Yay!";
    //         else cout << ":(";
    //     }
    //     else {
    //         if (a >= b / 2) cout << "Yay!";
    //         else cout << ":(";
    //     }
    // }


    int m = max(a, b);
    m > 8 ? cout << ":(" : cout <<"Yay!";
}