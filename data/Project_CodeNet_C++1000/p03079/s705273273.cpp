#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cfenv>
using ll = unsigned long long;
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
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b&&b==c){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}