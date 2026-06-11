#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    for(auto c : s){
        if(c == '1') cout << '9';
        if(c == '9') cout << '1';
    }
    cout << endl;
}