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

ll max(ll a,ll b){
    if(a > b) return a;
    return b;
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    ll tmp = 1;
    ll a_f,b_f;
    a--;
    while(tmp <= b){
        a_f = (a)/(2*tmp)*tmp + max(0,(a%(2*tmp))-tmp+1);
        b_f = (b)/(2*tmp)*tmp + max(0,(b%(2*tmp))-tmp+1);
        if(((b_f-a_f)%2)==1){
            ans += tmp;
        }
        tmp *= 2;
    }

    cout << ans << endl;
    return 0;
}