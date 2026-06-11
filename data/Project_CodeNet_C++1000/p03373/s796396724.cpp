#include<bits/stdc++.h>
#include<iomanip>
#include<numeric>

using namespace std;
using ll = long long;
constexpr int mo = 1e9+7;
constexpr int  mod = mo;
constexpr int inf = 1<<30;
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int pre = min(x,y);
    ll sum = pre*min(a+b,2*c);
    x -= pre;
    y -= pre;
    if(x>0){
        sum += x*min(a,2*c);
    }else if(y>0){
        sum += y*min(b,2*c);
    }
    cout << sum << endl;
    return 0;
}

