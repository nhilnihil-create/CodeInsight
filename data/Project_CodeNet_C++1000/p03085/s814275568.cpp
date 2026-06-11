#include <bits/stdc++.h>
using namespace std;

int main(){
    char b;
    cin >> b;
    vector<char> c(128);
    c.at('A')='T';
    c.at('T')='A';
    c.at('G')='C';
    c.at('C')='G';
    cout << c.at((int)b) << endl;
}