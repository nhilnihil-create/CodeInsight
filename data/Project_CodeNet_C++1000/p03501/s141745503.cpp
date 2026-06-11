#include<iostream>
using namespace std;
int main(void){
    int n,a,b = 0;
    cin >> n >> a >>b;
    if(n*a <= b){
        cout << n*a;
    }else{
        cout << b;
    }
}