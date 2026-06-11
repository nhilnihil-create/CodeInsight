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
#define REP(i,n) for(long long i(0);(i)<(n);(i)++)

const string YES = "YES";
const string NO = "NO";

void solve(std::string S){
    ll cnt = 0;
    for(auto x:S){
        if(x == 'x') cnt++;
    }
    cout << (cnt<=7? YES:NO)<<endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
