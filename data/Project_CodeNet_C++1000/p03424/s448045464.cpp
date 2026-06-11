#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int p=0, w=0, g=0, y=0;
    string s;

    for (int i=0; i<N; i++) {
        cin >> s;
        if (s=="P") p=1;
        if (s=="W") w=1;
        if (s=="G") g=1;
        if (s=="Y") y=1;
    }

    if (p+w+g+y == 4) {
        cout << "Four" << endl;
    } else if (p+w+g+y == 3) {
        cout << "Three" << endl;
    }
}
