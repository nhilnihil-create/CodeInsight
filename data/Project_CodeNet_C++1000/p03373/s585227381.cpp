#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
 
int main(){
    long long a,b,c,x,y,res;
    long long ans = 0;
    cin >> a >> b >> c >> x >> y;
    if( (a + b) / 2 > c){
        ans += min(x,y)*c*2;
        if(x > y){
            res = x - y;
            ans += res * a;
        }
        else if(y > x){
            res = y - x;
            ans += res * b;
        }
        if(c * max(x,y) * 2 <= ans){
            ans = c * max(x,y) * 2;
        }
    }
    else{
        ans += a * x + b * y;
        if(c * max(x,y) * 2 <= ans){
            ans = c * max(x,y) * 2;
        }
    }
    cout << ans << endl;
}