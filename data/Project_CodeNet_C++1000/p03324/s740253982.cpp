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


int main(){
    ll D, N;
    cin >> D >> N;

    ll ans = 0;
    ll count = 1;
    if(D == 0){
        ans = 1;
        while(count < N){
            if(ans % 100 != 99){
                count++;
            }
            ans++;
        }
    }else if(D == 1){
        ans = 100;
        while(count < N){
            if(ans % 10000 != 9900){
                count++;
            }
            ans += 100;
        }
    }else{
        ans = 10000;
        while(count < N){
            if(ans % 1000000 != 990000){
                count++;
            }
            ans += 10000;
        }
    }

    cout << ans << endl;

    return 0;
}