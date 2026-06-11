#include<iostream>
using namespace std;
int main(void){
    int a,b = 0;
    cin >> a >> b;
    int mm = a+b;
    if(mm < a-b){
        mm = a-b;
    }
    if(mm < a*b){
        mm = a*b;
    }
    cout << mm;
}