#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int sum = 0;
    int abmin = min(a+b,c*2);

    if(x >= y){
        sum += y*abmin;
        if(a > c*2){
            sum += (x-y)*c*2;
        }else{
            sum += (x-y)*a;
        }
    }else{
        sum += x*abmin;
        if(b > c*2){
            sum += (y-x)*c*2;
        }else{
            sum += (y-x)*b;
        }
    }
    cout << sum << endl;
}