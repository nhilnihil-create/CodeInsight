#include <iostream>
using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;
    int add = a + b;
    if(add % 2 != 0) cout << (add / 2)+1;
    else cout << add / 2;
    return 0;
}