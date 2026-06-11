#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b;
    string s;
    cin >>a >> b >> s;
    string ret = "Yes";
    for (int i = 0; i < a; i++ ) {if (s.at(i) == '-') {ret = "No";}}
    if (s.at(a) != '-') {ret = "No";}
    for (int i = 0; i < b; i++ ) {if (s.at(i+a+1) == '-') {ret = "No";}}
    cout << ret << endl;
    return 0;
}