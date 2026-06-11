#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main (void) {
    string str;
    size_t w;
    cin >> str;
    cin >> w;
    stringstream ss;
    for (size_t i = 0; w*i < str.size(); ++i) {
        ss << str[w*i];
    }
    cout << ss.str() << endl;
}