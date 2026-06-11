#include <iostream>
using namespace std;
int main(void){
    int a,b,ans;
    cin >> a >> b;
    if(a>b) cout << a+a-1;
    else if(b>a) cout << b+b-1;
    else cout << a+b;
}