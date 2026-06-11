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
#define ALL(a) a.begin(), a.end()

const string YES = "YES";
const string NO = "NO";

void solve(std::vector<long long> N){
    set<ll> st(ALL(N));
    if(st.count(1)&&st.count(9)&&st.count(7)&&st.count(4))
        cout << YES << endl;
    else
        cout << NO << endl;
}

int main(){
    std::vector<long long> N(4);
    for(int i = 0 ; i < 4 ; i++){
        scanf("%lld",&N[i]);
    }
    solve(std::move(N));
    return 0;
}
