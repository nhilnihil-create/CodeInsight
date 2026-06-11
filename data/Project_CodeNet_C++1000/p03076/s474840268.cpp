#include<iostream>
using namespace std;

int main(){
    int A,B,C,D,E,a,b,c,d,e,k,T;
    cin >> A >> B >> C >> D >> E;
    a = A%10;
    b = B%10;
    c = C%10;
    d = D%10;
    e = E%10;
    if(a==0) a = 10;
    if(b==0) b = 10;
    if(c==0) c = 10;
    if(d==0) d = 10;
    if(e==0) e = 10;
    k = min(a,min(b,min(c,min(d,e))));
    if(a!=10){
        A = A - A%10 + 10;
    }
    if(b!=10){
        B = B - B%10 + 10;
    }
    if(c!=10){
        C = C - C%10 + 10;
    }
    if(d!=10){
        D = D - D%10 + 10;
    }
    if(e!=10){
        E = E - E%10 + 10;
    }    
    T = A + B + C + D + E -10 + k;
    cout << T;
}