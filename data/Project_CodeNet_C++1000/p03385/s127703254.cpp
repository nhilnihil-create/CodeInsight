#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    bool flag = false;
    string S;
    cin >> S;
    if (S.find("a") != -1 && S.find("b") != -1 && S.find("c") != -1) {
        flag = true;
    }

    if (flag) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}