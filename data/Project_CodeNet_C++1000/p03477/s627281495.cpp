#include <iostream>
using namespace std;
int main(void){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int L = A + B;
    int R = C + D;
    if(L > R)
        cout << "Left" << endl;
    else if(L == R)
        cout << "Balanced" << endl;
    else
        cout << "Right" << endl;
}
