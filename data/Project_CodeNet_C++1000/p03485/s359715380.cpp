#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b;
    cin >> a >> b;
    if((a+b)%2) cout << (a+b)/2+1 << endl;
    else cout << (a+b)/2 << endl;
    return 0;
}
