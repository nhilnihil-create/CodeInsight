#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
//cout << std::fixed << std::setprecision(15) << y << endl;


// mod
#define MOD 1000000007

// 累乗mod
ll pmod(ll n, ll m){
    if(m == 0) return 1;
    if(m == 1) return n % MOD;
    if(m % 2 == 0){
        return pmod(n * n % MOD, m / 2) % MOD;
    }
    return n * pmod(n * n % MOD, (m - 1) / 2) % MOD;
}

int main(){
    ll N, K;
    cin >> N >> K;

    double ans = 0.0;
    ll throwsBefore;
    ll throws;
    ll minMaxPointsBefore;
    ll minMaxPoints;
    ll firstCheck = 1;
    for(ll i = N; i > 0; i--){
        throwsBefore = throws;
        minMaxPointsBefore = minMaxPoints;
        if(i >= K){
            minMaxPoints = i;
            throws = 0;
        }else{
            if(firstCheck == 1){
                minMaxPoints = i;
                throws = 0;
                while(minMaxPoints< K){
                    minMaxPoints *= 2;
                    throws++;
                }
                firstCheck = 0;
            }else{
                minMaxPoints = (minMaxPointsBefore / (i + 1)) * i;
                throws = throwsBefore;
                while(minMaxPoints < K){
                    minMaxPoints *= 2;
                    throws++;
                }
            }
        }
        ans += 1.0 / (double)(N * pmod((ll)2, throws));
    }

    cout << std::fixed << std::setprecision(12) << ans << endl;

    return 0;
}
