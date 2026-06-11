#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s,sref;
    struct tm stm = {0};
    struct tm ref = {0};
    cin >> s;
    sref = "2019/04/30"; 
    strptime(&s[0], "%Y/%m/%d", &stm);
    strptime(&sref[0], "%Y/%m/%d", &ref);

    if(difftime(mktime(&ref), mktime(&stm)) >= 0) {
        cout << "Heisei\n";
    } else {
        cout << "TBD\n";
    }
    
    return 0;
}
