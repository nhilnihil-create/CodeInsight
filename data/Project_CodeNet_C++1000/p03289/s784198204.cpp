#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    int size = s.size(), cnt = 0;
    bool flg = true;
    if (s.at(0) != 'A') flg = false;
    for (int i=1; i<size; i++){
        if (s.at(i) == 'C'){
            cnt++;
            if ((i < 2) || (i>=(size-1)) || (cnt!=1)){
                flg = false;
            }
            continue;
        }
        if (isupper(s.at(i))) flg = false;
    }
    if (cnt == 0) flg = false;

    if (flg) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
}