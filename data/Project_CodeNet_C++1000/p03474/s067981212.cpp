#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, s; cin >> a >> b >> s;
    cout << (regex_match(s, regex("\\d{"+a+"}-\\d{"+b+"}")) ? "Yes" : "No") << endl;
}