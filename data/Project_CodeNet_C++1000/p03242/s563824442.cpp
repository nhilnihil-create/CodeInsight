// Online C++ compiler to run C++ online.
// Write C++ code in this online editor and run it.

#include <bits/stdc++.h>
using namespace std ;

int main() {
    string s;
    cin >> s;
    for(auto &c:s){
        if(c == '1'){
            c = '9';
        } else if (c == '9'){
            c = '1';
        }
    }
    cout << s << endl;
    //std::cout << "Hello World!";
    return 0;
}