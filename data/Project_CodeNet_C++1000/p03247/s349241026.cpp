#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    cin >> x[0] >> y[0];
    ll c = abs(x[0] + y[0]) % 2;
    REP(i, n - 1){
        cin >> x[i + 1] >> y[i + 1];
        if(abs(x[i + 1] + y[i + 1]) % 2 != c){
            cout << -1 << endl;
            return 0;
        }
    }
    
    vector<ll> d;
    for(ll i = 30; i >= 0; i--){
        d.push_back(1LL << i);
    }
    if(c == 0){
        d.push_back(1);
    }
    
    ll m = d.size();
    cout << m << endl;
    REP(i, m){
        cout << d[i] << ' ';
    }
    cout << endl;
    REP(i, n){
        string w;
        ll dx = 0, dy = 0;
        REP(j, m){
            if(abs(x[i] - dx) >= abs(y[i] - dy)){
                if(x[i] < dx){
                    w += 'L';
                    dx -= d[j];
                }
                else{
                    w += 'R';
                    dx += d[j];
                }
            }
            else{
                if(y[i] < dy){
                    w += 'D';
                    dy -= d[j];
                }
                else{
                    w += 'U';
                    dy += d[j];
                }
            }
        }
        cout << w << endl;
    }
}
