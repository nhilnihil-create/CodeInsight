#include <iostream>

using namespace std;

int main(){
    int x, y, Max;
    cin >> x >> y;
    Max = x * y;
    if(Max < (x+y))
        Max = x+y;
    if(Max < (x-y))
        Max = x-y;
    
    cout << Max <<endl;
    
    return 0;
}