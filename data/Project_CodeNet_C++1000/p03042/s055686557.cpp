#include <iostream>
using namespace std;

int main() {
    int S ; // 4 digit sequence
    cin >> S;
    int A = S / 100;
    int B = S % 100; 
    if (A >= 01 && A <= 12){
        if (B >= 01 && B <= 12) cout << "AMBIGUOUS";
        else cout << "MMYY";
     } 
     else {
        if (B >= 01 && B <= 12) cout << "YYMM";
        else cout << "NA";
     }
    return 0;
}