#include <iostream>
using namespace std;
int main(void){
    int N, A, B;
    cin >> N >> A >> B;
    if (A*N>B){
        cout << B << endl;
    }
    else {
        cout << A*N << endl;
    }
}
