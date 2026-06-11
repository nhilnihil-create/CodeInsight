#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;


int main() {
   
    long double ans = 0;
    ll n;
    cin >> n;
    static const ll MAX = 201;
    ll t[MAX] = {};
    ll v[MAX] = {};
    for (ll i=1;i<=n;i++){
        cin >> t[i];
    }
    for (ll i=1;i<=n;i++){
        cin >> v[i];
    }
    ll tsum[MAX] = {};
    ll tmp = 0;
    for (ll i=1;i<=n;i++){
        tmp += t[i];
        tsum[i] = tmp;
    }
    ll vnow = 0;
    ll lim1, lim2;
    lim1 = mop;
    lim2 = 0;
    ll tidx = 1;
    for (ll i=0;i<tsum[n];i++){
        if(i == tsum[tidx-1]){
            lim2 = v[tidx];
            tidx++;
        }
        ll tmp = 0;
        lim1 = mop;
        for (ll j=tidx-1;j<=n;j++){
            tmp = tsum[j] - i + v[j+1];
            if(lim1 > tmp){
                lim1 = tmp;
            }
        }

        if(lim1 - vnow >= 2){
            if(lim2 - vnow >= 1){
                ans += vnow + 0.5;
                vnow++;
            }else{
                ans += vnow;
            }
        }else if(lim1 - vnow == 1){
            if(lim2 - vnow >= 1){
                ans += vnow + 0.25;
            }else{
                ans += vnow;
            }
        }else{
            ans += vnow - 0.5;
            vnow--;
        }
//        cout << i << " " << vnow << " " << lim1 << endl;
    }
    cout << fixed;
    cout << setprecision(5);
    cout << ans << endl;



}