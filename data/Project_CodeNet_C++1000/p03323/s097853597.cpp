#include<iostream>
using namespace std;
int main(void){
    int a,b = 0;
    cin >> a >> b;
    if(a > 8 || b > 8){
        cout << ":(";
    }else{
        cout << "Yay!";
    }
}