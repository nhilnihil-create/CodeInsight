#include <bits/stdc++.h>

using namespace std;


int main() {

    int a, b, x;
    string res1 = "YES";
    string res2 = "NO";

    cin >> a;
    cin >> b;
    cin >> x;

    if (x>a+b || x<a) {

         cout << res2 << endl;        
    } 

    else if(x>=a && x<=a+b) {

        cout << res1 << endl;
    }   

    return 0;
}

