#include <bits/stdc++.h>
using namespace std;

int main(){
    char buf[4];
    
    cin >> buf;
    int a = atoi(buf);

    cin >> buf;
    int b = atoi(buf);

    cin >> buf;
    int c = atoi(buf);

    if(a == b){
        cout << c << endl;
    }else if(a == c){
        cout << b << endl;
    }else{
        cout << a << endl;
    }
}