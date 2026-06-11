#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
using ll = long long;
using namespace std;
int main(){
    int a,b,c,x,y;
    cin >>a >>b >>c >> x >> y;
    long long count=0;
    if(c*2<a+b){
        count += min(x,y)*c*2;
    }else{
        cout<<a*x+b*y<<endl;
        return 0;
    }
    if(x-min(x,y)>0){
        count += min((x-min(x,y))*a,(x-min(x,y))*c*2);
    }else{
        count += min((y-min(x,y))*b,(y-min(x,y))*c*2);
       // cout<<min((y-min(x,y))*b,(x-min(x,y))*c*2)<<endl;
    }
    cout<<count<<endl;
}
