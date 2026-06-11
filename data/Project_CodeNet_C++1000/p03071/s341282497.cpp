#include <iostream>
using namespace std;
int main(void){
    int a,b;
    cin >> a >> b;
    if(a>=b+1) cout << 2*a -1 << endl;
    else if(a+1<= b) cout << 2*b -1 << endl;
    else if(a==b) cout << a + b << endl;
}