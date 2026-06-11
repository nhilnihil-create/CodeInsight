#include <bits/stdc++.h>
using namespace std;  

int main(){
    int n, x, y;
    string s = "No";
    
    cin >> n;
    x = y = 0;
    while ( x <= n && s == "No") {
        y = 0;
        while ( x+y <= n && s == "No" ) {
            if ( x+y == n ) {
                s = "Yes";
            }
            y+=7;
        }
        x+=4;
    }
    
    cout << s << endl;
    
    return (0);
}
