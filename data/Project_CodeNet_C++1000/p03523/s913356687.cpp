#include<iostream>
#include<string>
#include<regex>
using namespace std;

int main (){
    regex re("A?KIHA?BA?RA?");
    string s;
    cin >> s;
    bool res = regex_match(s, re);
    cout << (res ? "YES" : "NO" ) << endl;
    
    return 0;
}