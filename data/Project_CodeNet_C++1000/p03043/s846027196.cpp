#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using ld = long double;


ld f(int i,int k){
    ll num = i;
    ld time = 0.0;
    while(num < k){
        num *= 2;
        time++;
    }    
    return time;
}

int main(){
    ll n,k;
    cin >> n >> k;
    ld ans = 0;
    reps(i,1,n+1){
        ld tmp = (ld)1/n * pow((ld)0.5,f(i,k));
        ans += tmp;
    }
    
    cout << setprecision(30) << ans << endl;
}