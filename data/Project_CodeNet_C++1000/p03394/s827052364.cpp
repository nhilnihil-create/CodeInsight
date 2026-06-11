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
    if(n == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    if(n == 4){
        cout << "2 5 20 63" << endl;
        return 0;
    }
    if(n == 5){
        cout << "2 3 4 6 9" << endl;
        return 0;
    }
    ll cnt = 0, sum = 0;
    vector<ll> a;
    for(ll i = 2; i <= 30000; i++){
        if(i % 2 == 0 || i % 3 == 0){
            a.push_back(i);
            sum += i;
            cnt++;
        }
        if(cnt == n) break;
    }
    if(sum % 6 == 2){
        a[4] = a.back() + (6 - (a.back() % 6));
    }
    else if(sum % 6 == 3){
        a[5] = a.back() + (6 - (a.back() % 6));
    }
    else if(sum % 6 == 5){
        ll t = a.back() + 1;
        while(t % 6 != 4){
            t++;
        }
        a[5] = t;
    }
    REP(i, n){
        cout << a[i] << " \n"[i == n - 1];
    }
}