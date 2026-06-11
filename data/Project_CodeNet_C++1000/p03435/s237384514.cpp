#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int c11, c12, c13, c21, c22, c23, c31, c32, c33;
    cin >> c11 >> c12 >> c13 >> c21 >> c22 >> c23 >> c31 >> c32 >> c33;
    
    for (int i = 0; i <= c11; i++) {
        int a1 = i;
        int b1 = c11 - a1, b2 = c12 - a1, b3 = c13 - a1;
        int a2 = c21 - b1, a3 = c31 - b1;
        if (a2+b1==c21 && a2+b2==c22 && a2+b3==c23 && 
            a3+b1==c31 && a3+b2==c32 && a3+b3==c33) continue;
            else {
                cout << "No" << endl;
                return 0;
            }
    }
    
    cout << "Yes" << endl;
}
