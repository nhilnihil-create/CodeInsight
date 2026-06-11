#include <iostream>
#include <string>
using namespace std;

int main (void){
    string str;
    cin >> str;
    if ((str.find('a') != string::npos) && (str.find('b') != string::npos) && (str.find('c') != string::npos)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
