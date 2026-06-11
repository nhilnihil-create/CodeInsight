#include <bits/stdc++.h>

using namespace std;
int main(void){
    // Your code here!
    int a, b;
    cin >> a >> b;
    
    int seki = a * b;
    
    if ( seki % 2 != 0 ){
        cout << "Odd" << endl;
    } else if ( seki % 2 == 0){
        cout << "Even" << endl;
    } else {
        cout << "Even" << endl;
    }
}