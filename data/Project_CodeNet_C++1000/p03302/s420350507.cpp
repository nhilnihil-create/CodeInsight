#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int a,b;
    cin >> a >> b;
    string ans = "x";
    if(a + b == 15){
        ans = "+";
    }
    if(a * b == 15){
        ans = "*";
    }
    cout << ans << endl;
}
