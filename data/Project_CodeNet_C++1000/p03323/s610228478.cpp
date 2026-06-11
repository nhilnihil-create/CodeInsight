#include <bits/stdc++.h>

using namespace std;


int main() {

    int a,b;
    string res1, res2;
    res1 = "Yay!";
    res2 = ":(";
    cin >> a;
    cin >> b;

    if(a+b<=16 && a<=8 && b<=8) {
        cout << res1 << '\n';
    }
    else if(a+b<=16 && a>8 || b>8) {
        cout << res2 << '\n';
    }
   
    return 0;
}
