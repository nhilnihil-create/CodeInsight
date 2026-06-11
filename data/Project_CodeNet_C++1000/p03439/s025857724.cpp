#include <iostream>
#include <vector>

using namespace std;

int query(int i) {
    cout << i << endl << flush;
    string s;
    cin >> s;
    if(s=="Vacant") {
        exit(0);
    } else if(s=="Male") {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n;
    cin >> n;
    int l = 0, r = n, ls, rs;
    ls = rs = query(l);
    for(int t=1; t<20; t++) {
        int m = (l + r + 1) / 2;
        int ms = query(m);
        if(((m-l)&1)^(ls^ms)) {
            r = m;
            rs = ms;
        } else {
            l = m;
            ls = ms;
        }
    }
}
