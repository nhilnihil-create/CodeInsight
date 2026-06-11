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


void solve(long long N, std::string A, std::string B, std::string C){
    ll cnt  = 0;
    REP(i, N){
        set<char> tmp;
        tmp.insert(A[i]); tmp.insert(B[i]); tmp.insert(C[i]);
        if(tmp.size()==2){
            cnt ++;
        }
        else if(tmp.size() == 3){
            cnt +=2;
        }
    }
    cout << cnt << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string A;
    std::cin >> A;
    std::string B;
    std::cin >> B;
    std::string C;
    std::cin >> C;
    solve(N, A, B, C);
    return 0;
}
