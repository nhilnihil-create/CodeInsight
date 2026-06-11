#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int A = max(max(a,b),c);

    cout << (a+b+c-A)+10*A << endl;

    return 0;
}