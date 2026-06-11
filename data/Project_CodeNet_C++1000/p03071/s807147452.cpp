#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    if(abs(a-b)<=1){
        cout << a+b << endl;
    }else{
        cout << max(a,b)*2 - 1 << endl;
    }
}