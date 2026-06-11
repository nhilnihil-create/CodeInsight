#include<iostream>
using namespace std;
int main(void){
    int a,b,c,d = 0;
    cin >> a >> b >> c >> d;
    bool yn = 0;
    if(abs(a-c) <= d){
        yn = 1;
    }else if(abs(a-b)<= d && abs(b-c) <= d){
        yn = 1;
    }
    if(yn){
        cout << "Yes";
    }else{
        cout << "No";
    }
}