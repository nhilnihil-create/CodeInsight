#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int X;
    cin >> X;
    if(X < 4) {
        cout << "1\n";
        return 0;
    }

    set<int> s;
    for(int i=2;i<33;i++) {
        for(int j=2;;j++) {
            int r = pow(i,j);
            if(r > 1000) break;
            s.insert(r);
        }
    }

    set<int>::iterator it = s.lower_bound(X);
    while((*it) > X) {
        it--;
    }
    cout << *it << endl;
    
    return 0;
}
