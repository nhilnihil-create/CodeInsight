#include <iostream>
using namespace std;
int main(void){
    int a, b;
    cin >> a >> b;
    
    int num = 0;
    for (int i=1; i<b-a; i++) num += i;
    
    cout << num - a << endl;
    
    return 0;
}