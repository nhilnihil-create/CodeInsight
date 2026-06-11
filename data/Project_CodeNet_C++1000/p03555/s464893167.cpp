#include <iostream>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    bool flag=true;
    for(int i=0; i<3; i++) {
        if(str1[i]!=str2[2-i]) {
            flag=false;
            break;
        }
    }
    if(flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
    
}