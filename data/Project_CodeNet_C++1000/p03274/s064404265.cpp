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
    int n,k;
    cin >> n >> k;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];

    ll ans = 1e14;
    rep(i,n-k+1){
        ll right = x[n-1-i];
        ll left = x[n-i-k];
        ll tmp =0;
        
        if (left >= 0) tmp = right;
        else if(right <= 0) tmp = abs(left);
        else{
            if(abs(left) >= right)tmp = right*2+abs(left);
            else tmp = right+abs(left)*2;
        }

        ans = min(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}
