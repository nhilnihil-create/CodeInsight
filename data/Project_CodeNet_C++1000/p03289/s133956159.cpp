#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    if (str[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    
    int index;
    int flag = 0;
    for (int i = 2; i < str.size() - 1; i++) {
        if (str[i] == 'C') {
            flag = 1;
            index = i;
        }
    }
    
    int up = 0;
    
    for (int i = 1; i < str.size(); i++) {
        if (i == index) {
            continue;
        }
        if (isupper(str[i])) {
            up = 1;
        }
    }
    
    if (up == 0 && flag == 1) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
    
    return 0;
}