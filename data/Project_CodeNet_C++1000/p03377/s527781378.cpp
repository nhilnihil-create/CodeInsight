#include<iostream>
using namespace std;
int main(void){
    int a,b,x= 0;
    cin >> a >> b >> x;
    if(x < a){
        cout << "NO";
    }else if(a+b >= x){
        cout << "YES";
    }else{
        cout << "NO";
    }
}