#include <iostream>

using namespace std; 

int main(){
    int x;

    cin >> x;

    if(x % 2){
        cout << 2*x;

    }else{
        cout << x;
    }

    return 0;
}