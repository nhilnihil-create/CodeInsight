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
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;

ll digitSum(ll x){
    ll sum = 0;
    while(x > 0){
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int main(){
    ll N, A, B;
    cin >> N >> A >> B;

    ll ans = 0;
    REP(i, N){
        ll sum = digitSum(i);
        if(sum >= A && sum <= B){
            ans += i;
        }
    }

    cout << ans << endl;
    
    return 0;
}