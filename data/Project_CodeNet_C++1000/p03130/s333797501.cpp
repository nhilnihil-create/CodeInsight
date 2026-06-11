#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)

const string YES = "YES";
const string NO = "NO";

void solve(std::vector<long long> a, std::vector<long long> b){
    map<ll, ll> mp;
    rep(i, 3){
        mp[a[i]]++;
        mp[b[i]]++;
    }
    ll cnt = 0;
    for(auto x: mp){
        if(x.second & 1)
            cnt ++;
    }
    if (cnt > 2)
        cout << NO << endl;
    else
        cout << YES << endl;
}

int main(){
    std::vector<long long> a(3);
    std::vector<long long> b(3);
    for(int i = 0 ; i < 3 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    solve(std::move(a), std::move(b));
    return 0;
}
