#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
using ll = long long;
using namespace std;
int gcd(int x,int y){
    if(y==0){
        return x;
    }else{
        return gcd(y,x%y);
    }
}
int lcm(int x,int y){
    return x/gcd(x,y)*y;
}
int main(){
    int a,b;
    cin >> a >> b;
    int c=a-b+1;
    if(c<0){
        cout<<0<<endl;
    }else{
        cout<<c<<endl;
    }
}