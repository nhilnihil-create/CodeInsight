#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int a;

    cin >> a;

    if( ( a % 2 ) == 0 ){
        cout << a << "\n";
    }
    else{
        cout << a * 2 << "\n";
    }
}