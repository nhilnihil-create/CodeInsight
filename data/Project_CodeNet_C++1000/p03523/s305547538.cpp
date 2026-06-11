#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string sub1 = "KIH", sub2 = "B", sub3 = "R";
    string ans = "NO";
    for(int bit = 0; bit < (1 << 4); bit++){
        string coans = "";
        if(bit & 1) coans += 'A';
        coans += sub1;
        if(bit & (1 << 1)) coans += 'A';
        coans += sub2;
        if(bit & (1 << 2)) coans += 'A';
        coans += sub3;
        if(bit & (1 << 3)) coans += 'A';

        if(s == coans) ans = "YES";
    }
    cout << ans << endl;
    return 0;
}