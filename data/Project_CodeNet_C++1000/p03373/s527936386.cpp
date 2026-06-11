#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,x,y;
    long int sum = 0;
    cin >> a >> b >> c >> x >> y;
    int max,min,max2;
    if(x>y){
        max=x;
        if(a > 2*c)max2 = 2*c;
        else max2 = a;
        min=y;
    } else {
        max=y;
        if(b > 2*c)max2 = 2*c;
        else max2 = b;
        min=x;
    }
    if((2*c) > (a+b))sum = min*(a+b);
    else sum = min*2*c;
    sum += (max-min)*max2;
    cout << sum;
}