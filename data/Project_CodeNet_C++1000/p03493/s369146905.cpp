#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int tama = 0;
    string s;
    cin >> s;
    
    for ( int i = 0; i < s.size(); ++i ){
        
        
        if ( s[i] == '1' ){
            ++tama;
        }
    
    }

    cout << tama << endl;
}
