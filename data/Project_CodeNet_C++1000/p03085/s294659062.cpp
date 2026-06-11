#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    char b;
    cin >> b;

    switch (b) {
        case 'A':
            cout << 'T';
            break;
        case 'C':
            cout << 'G';
            break;
        case 'G':
            cout << 'C';
            break;
        case 'T':
            cout << 'A';
            break;
    }
    cout << endl;

    return 0;
}
