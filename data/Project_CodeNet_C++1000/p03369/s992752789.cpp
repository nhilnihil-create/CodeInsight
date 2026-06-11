#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    
    int money = 700;
    
    for ( int i = 0; i < 3; ++i ) {
        char S;
        cin >> S;
        
        if ( S == 'o' ){
            money = money + 100;
        }
    }

    cout << money << endl;
}
