#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    while (s[0] != s[1] || s[1] != s[2])
    {
        s = to_string(stoi(s) + 1);
    }
    cout << s << endl;
}