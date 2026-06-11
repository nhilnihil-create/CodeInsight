#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    if(c - (a+b) <= 1)cout << c+b;
    else cout << c - (c - (a+b)) + 1 + b;
} 