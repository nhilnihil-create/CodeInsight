#include <iostream>
using namespace std;

int main(void) {
    int N,A,B;cin>>N>>A>>B;
    if (N * A <= B) cout << N * A << endl;
    else cout  << B << endl;
    return 0;
}