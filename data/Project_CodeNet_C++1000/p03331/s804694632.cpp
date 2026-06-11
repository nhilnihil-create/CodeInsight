#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n, num = 0;
    cin >> n;
    while(n){
        num += n%10;
        n /= 10;
    }

    if(num == 1)
        cout << 10 << endl;
    else
        cout << num << endl;
    

    return 0;
}