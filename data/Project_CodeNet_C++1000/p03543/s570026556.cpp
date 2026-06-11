#include <iostream>
using namespace std;

int main(){
    string s;
    bool a;
    cin >> s;
    
    if ((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3])){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    
}