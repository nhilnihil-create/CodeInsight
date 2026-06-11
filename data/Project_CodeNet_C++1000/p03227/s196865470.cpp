#include <bits/stdc++.h>

using namespace std;


int main()
{
    string str;
    char tmp;

    cin >> str;

    if ((int)str.length() == 2) {
        cout << str << endl;
    } else {
        tmp = str[0];
        str[0] = str[2];
        str[2] = tmp;
        cout << str << endl;
    }
    
    return 0;   
}