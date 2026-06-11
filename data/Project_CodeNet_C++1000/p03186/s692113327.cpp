#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int d = 0;
    if(b <= c)
    {
        d += b * 2;
        c -= b;
        b = 0;
    }
    if(b > c){
        d += b;
        d += c;
        b = 0; c = 0;
    }
    if(c > 0 && a > 0 && c <= a)
    {
        d += c;
        c = 0;
    }
    else if( c > 0 && a > 0 && c > a){
        d += a;
        c-= a;
    }
    if(c > 0)
    d++;
    cout << d << endl;
}