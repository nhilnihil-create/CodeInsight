#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    double T, X, t;
    cin >> T >> X;
    t = T/X;
    cout << setprecision(64) << t << endl;
}