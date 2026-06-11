#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int i,r,D,x,x_next;
    cin >> r >> D>> x; 
    for(i=1;i<=10;i++){
        x_next = r * x - D;
        cout << x_next << endl;
        x = x_next;
    }
    return 0;
}