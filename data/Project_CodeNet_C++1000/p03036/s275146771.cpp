#include<iostream>
using namespace std;

int main(){
    long r,d,x_init;
    cin >> r >> d >> x_init;

    long x = x_init;
    for(int i=0; i<10; i++){
        x = r*x - d; 
        cout << x << endl;
    }

    return 0;
}