#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main(){
    int a,b,c,res;

    cin >> a >> b >> c;

    res = abs(a-b) + abs(b-c);
    if( res > ( abs(b-a) + abs(a-c) ) ){
        res = abs(b-a) + abs(a-c);
    }
    if( res > ( abs(c-a) + abs(c-b) ) ){
        res = abs(c-a) + abs(c-b);
    }

        cout << res << "\n";
}