#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin >>a >> b >> c;
    int buffer1, buffer2;
    if(a==b){
        cout << c << endl;
    }
    else if(a==c){
        cout << b << endl;
    }
    else{
        cout << a << endl;
    }
}