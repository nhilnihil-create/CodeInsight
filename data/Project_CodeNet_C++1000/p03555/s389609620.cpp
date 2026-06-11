#include <iostream>
using namespace std;

int main(void) {
    char c11,c12,c13;cin>>c11>>c12>>c13;
    char c21,c22,c23;cin>>c21>>c22>>c23;
    if (c11 == c23 && c22 == c12 && c21 == c13) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}