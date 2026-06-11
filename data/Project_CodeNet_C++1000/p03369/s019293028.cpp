#include <bits/stdc++.h>
using namespace std;

int main(void){
    string str;
    cin >> str;
    int a = 0;
    for (int i=0; i<3; i++) if (str[i] == 'o') a++;
    cout << 700 + 100 * a << endl;
    return 0;
}