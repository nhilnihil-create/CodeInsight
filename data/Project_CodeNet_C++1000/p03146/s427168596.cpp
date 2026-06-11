#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a;
    int an,cnt = 0;
    
    cin >> a;
    an = a;
    unordered_set<int> mp;
    for(int i=1;;i++) {
        if(mp.find(an) == mp.end()) {
            mp.insert(an);
        } else {
            cout << i << endl;
            break;
        }
        if(an%2) {
            an = 3*an + 1;
        } else {
            an = an / 2;
        }
    }
    return 0;
}
