#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int x, d;
    x = s.length();
    bool a, b, c;
    a = (s[0] == 'A');
    for(int i = 2; i < x - 1 ; i++){
        if(s[i] == 'C') d++;
    }
    b = (d == 1);
    for(int i = 1; i < x; i++){
        if(s[i] >= 97 && s[i] <= 122) d++;
    }
    c = (x - 1 == d);
    if(a && b && c){
        cout << "AC" << endl;
    }
    else{
        cout << "WA" << endl;
    }
}