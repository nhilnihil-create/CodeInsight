#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    int mindiff = INT_MAX;
    int diff ,cur;
    cin >> s;

    for(int i=0;i<s.size()-2;i++) {
        cur = (s[i]-'0')*100 + (s[i+1]-'0')*10 + s[i+2]-'0';
        diff = abs(753 - cur);
        if(mindiff > diff) {
            mindiff = diff;
        }
    }

    cout << mindiff << endl;

    return 0;
}
