#include <iostream>

using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B>>C;
    if(A==B&&C!=A) cout<<C;
    if(A==C&&B!=A) cout<<B;
    if(B==C&&A!=B) cout<<A;
    return 0;
}