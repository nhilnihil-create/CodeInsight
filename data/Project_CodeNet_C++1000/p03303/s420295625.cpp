#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int w;
    cin >> w;
    int a=0;
    while(1){
        cout << s[a];
        a+=w;
        if(a>=s.size()) break;
    }
    return 0;
}