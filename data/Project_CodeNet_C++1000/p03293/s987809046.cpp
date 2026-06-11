#include <bits/stdc++.h>
using namespace std;

int main(){

    string s, t;
    cin >> s >> t;

    int num = s.size();
    bool flg = false;
    string buf = s;
    for (int i=0; i<num; i++){
        char cbuf = buf.at(num-1);
        buf.erase(num-1);
        buf = cbuf + buf;

        if (buf == t) flg = true;
    }

    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}