#include <iostream>
using namespace std;
int main(){
    long long k, a, b;
    cin >> k >> a >> b;
    if( a < b - 2 ){
        long long biscuit = a;
        k -= a - 1;
        biscuit += (k/2) * (b-a) + k%2;
        cout << biscuit << endl;
    } else {
        cout << k + 1 << endl;
    }
    return 0;
}