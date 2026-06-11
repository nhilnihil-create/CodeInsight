#include<iostream>
using namespace std;
int main(void){
    char b;
    cin >> b;
    if(b == 'A'){
        cout << 'T';
    }else if(b == 'C'){
        cout << 'G';
    }else if(b == 'G'){
        cout << 'C';
    }else{
        cout << 'A';
    }
}