#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    int redcnt = 0;
    int bluecnt = 0;
    cin >> s;

    for(int i=0;i<s.size();i++) {
        if(s[i] == '0')redcnt++;
        else bluecnt++;
    }

    cout << min(redcnt,bluecnt) *2 << endl;
    return 0;
}
