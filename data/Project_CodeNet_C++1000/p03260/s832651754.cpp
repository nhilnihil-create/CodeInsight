#include <iostream>
using namespace std;

int main(void) {
    int A,B;cin>>A>>B;
    if ((A == 1 || A == 3) && (B == 1 || B == 3)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}