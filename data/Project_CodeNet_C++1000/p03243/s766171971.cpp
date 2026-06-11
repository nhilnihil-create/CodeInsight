#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int a,b,c;
    c = N % 10;
    N /= 10;
    b = N % 10;
    N /= 10;
    a = N;
    
    if(a >= b && a >= c){
       cout << a << a << a << endl; 
    }else{
        cout << a+1 << a+1 << a+1 << endl;
    }
    
}