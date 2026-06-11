#include<iostream>
using namespace std;
int main(void){
    int n = 0;
    cin >> n;
    if(n < 1200){
        cout << "ABC";
    }else if(n < 2800){
        cout << "ARC";
    }else{
        cout << "AGC";
    }
}