#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    
    unsigned long int len = s.length();
    
    int c_counter = 0;
    for (int i = 2; i <= len - 2; i++) {
        if (s[i] == 'C') c_counter++;
    }
    if (c_counter != 1) {
        cout << "WA" << endl;
        return 0;
    }
    
    for (int i = 0; i < len; i++) {
        if (s[i] != 'A' && s[i] != 'C' && !('a' <= s[i] && s[i] <= 'z') ) {
            cout << "WA" << endl;
            return 0;
        }
    }
    
    cout << "AC" << endl;
    
    
    return 0;
}
