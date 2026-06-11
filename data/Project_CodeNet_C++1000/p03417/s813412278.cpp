#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    if(n >= 2 && m >= 2){
        ans = (n-2)*(m-2);
    }else if(n == 1 && m == 1){
        ans = 1;
    }else if(n == 1 || m == 1){
        ans = max(n,m) - 2;
    }


    cout << ans << endl;
    return 0;
}