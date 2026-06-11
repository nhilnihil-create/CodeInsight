#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b;
    long int add,sub,mul;
    cin >> a >> b;
    add = a+b;
    sub = a-b;
    mul = a*b;
    cout << max({add,sub,mul}) << endl;
}
