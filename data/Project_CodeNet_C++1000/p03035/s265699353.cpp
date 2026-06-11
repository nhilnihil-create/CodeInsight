#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
    int a, b;
    int money = 0;
    cin >> a >> b;
    if(13 <= a){
        money += b;
    }else if(6 <= a){
        money += b / 2;
    }
    cout << money << endl;
    return 0;
}
