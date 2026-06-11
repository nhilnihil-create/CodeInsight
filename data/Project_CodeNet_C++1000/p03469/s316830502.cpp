#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s[3] != '8') {
        s[3] = '8';
        cout << s << endl;
    }
    else cout << s << endl;
    
}