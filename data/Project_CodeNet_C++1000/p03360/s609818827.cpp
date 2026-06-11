#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int A,B,C,K;cin>>A>>B>>C>>K;
    if (A > B) swap(A, B);
    if (A > C) swap(A, C);
    if (B > C) swap(B, C);
    cout << A + B + C * pow(2, K) << endl;
    return 0;
}