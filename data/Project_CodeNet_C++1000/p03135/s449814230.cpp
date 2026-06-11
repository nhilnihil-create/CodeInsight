#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    double t,x;
    cin >> t >> x;
    cout << fixed << setprecision(3) << t/x << endl;
}