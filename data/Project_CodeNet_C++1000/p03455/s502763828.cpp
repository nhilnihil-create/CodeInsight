#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int a, b;
    string out;
    cin >> a >> b;
    
    if((a*b)%2 == 0){
        out = "Even";
    }else{
        out = "Odd";
    }
    cout << out << endl;
    return 0;
}
