#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b,pos;
    cin >> a >> b;
    pos = b - a;
    cout << pos*(1+pos)/2 - b << endl;

    return 0;
}
