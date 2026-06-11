#include <iostream>

using namespace std;

int main() {
    int ch[3]={0};
    string str;
	cin >> str;
    bool flag = true;
    for(int i=0; i<3; i++) {
        if(ch[(int)(str[i]-'a')]==0) {
            ch[(int)(str[i]-'a')]++;
        } else {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
    
}