#include <iostream>
#include <string>
using namespace std;

int main (void){
    int a, b;
    int cnt = 0;
    cin >> a >> b;
    if(a == b){
        cout << a << endl;
    }else if(a < b){
        cout << a << endl;
    }else{
        cout << a - 1 << endl;
    }
    return 0;
}
