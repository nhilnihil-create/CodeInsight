#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b ;
    cin >>a >>b;

    int c , d ,e , f , i , j;
    c = a /100;
    d = b /100;

    e = a /10000;
    f = b /10000;

    i = (a%10000)/1000;
    j = (b%10000)/1000;

    if (100*c + 10* i + e< a && 100*d + 10* j + f > b){
        cout << d-c-1 << endl;
    }
    else if (100*c + 10* i + e >= a && 100*d + 10* j + f <= b){
        cout << d-c+1 << endl;
    }
    else {
        cout << d-c << endl;
    }



}