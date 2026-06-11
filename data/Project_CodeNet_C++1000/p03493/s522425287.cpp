#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    s = "0 , 0 , 0";
    int c;
    c = 0;
    cin >> s;
    if (s.at(0) == '1')
        c++;
    if (s.at(1) == '1')
        c++;
    if (s.at(2) == '1')
        c++;
    cout << c << endl;
}