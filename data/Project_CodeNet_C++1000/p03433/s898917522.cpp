#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int count = 0;
    int amari = 0;
    if (a>=500){
        amari = a % 500;
        count = a/500;
    }

    if (amari<=b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    
    
}