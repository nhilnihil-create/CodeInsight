#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    double a, b;
    cin >> a >> b;

    double x = (a + b) / 2; 
    int sei = (a + b) / 2;
    
    double syo = x - sei;
    if ( syo >= 0.5){
        ++sei;
    } 
    cout << sei << endl;
}
