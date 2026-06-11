#include <iostream>
#include <string>
using namespace std;
int main(void){
    
    int N;
    cin >> N;
    
    if(N / 100 == 1){
        cout << 9;
    }
    else{
        cout << 1;
    }
    if((N % 100) / 10 == 1){
        cout << 9;
    }
    else{
        cout << 1;
    }
    if(N % 10 == 1){
        cout << 9 << endl;
    }
    else{
        cout << 1 << endl;
    }
    
}
