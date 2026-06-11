#include <iostream>
using namespace std;

int main() {
    long long int a, b, x;
    cin >> a >> b >> x;
    if(x > a + b || a > x){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}