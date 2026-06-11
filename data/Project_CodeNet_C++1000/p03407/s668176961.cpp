#include<iostream>
using namespace std;

int main(void){
    int a,b,c = 0;
    cin >> a >> b >> c;
    int sum = a+b;
    if(c > sum){
        cout << "No";
    }else
    {
        cout << "Yes";
    }
    
}