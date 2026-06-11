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


void solve(ll N){
    vector<bool> a(N+1); //* false: female, true: male
    string s;
    cout << 0 << endl;
    cin >> s;
    if(s == "Vacant") 
        return;
    if(s == "Male")
        a[N]=a[0] = true;
    else
        a[N]=a[0] = false;
    ll lo = 0, hi = N;
    while(hi - lo > 1){
        ll mid = (lo + hi)/2;
        cout << mid << endl;
        cin >> s;
        if(s == "Vacant") 
            return;
        a[mid] = (s=="Male"? true: false);
        if((a[lo] == a[mid]) == ((mid-lo)&1)){
            hi = mid;
            continue;
        }
        if((a[mid] == a[hi]) == ((hi-mid)&1)){
            lo = mid;
            continue;
        }
    }
    
}

int main(){
    ll N;
    std::cin >> N;
    solve(N);
    return 0;
}
