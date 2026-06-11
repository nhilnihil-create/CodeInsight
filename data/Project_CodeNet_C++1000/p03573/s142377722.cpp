#include <iostream>
using namespace std;

int main(void) {
    int A,B,C;cin>>A>>B>>C;
    if (A == B) cout << C << endl;
    else if (A == C) cout << B << endl;
    else cout << A << endl;
    return 0;
}