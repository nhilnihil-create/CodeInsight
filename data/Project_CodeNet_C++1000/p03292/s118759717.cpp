#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main (void){
    int a, b, c;
    int d, e, f;
    int cost = 0;

    cin >> a >> b >> c;

    d = abs(a - b);
    e = abs(b - c);
    f = abs(c - a);

    if(a < b && a < c){
        if(b < c){
            cost += d + e; 
        }else{
            cost += f + e;
        }
    }else if(b < a && b < c){
        if(a < c){
            cost += d + f;
        }else{
            cost += e + f;
        }
    }else if(c < a && c < b){
        if(a < b){
            cost += f + d;
        }else{
            cost += e + d;
        }
    }else{
        if(a == b){
            cost += f;
        } else if(b == c){
            cost += d;
        }else if(c == a){
            cost += e;
        }else{

        }
    }

    cout << cost << endl;
    return 0;
}
