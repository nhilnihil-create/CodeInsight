#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int t,x;
    cin >> t >> x;

    cout << setprecision(12) << (double)t/x << endl;

    return 0;
}