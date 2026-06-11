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


void solve(long long A, long long B, long long K){
    rep(_, K){
        if(!(_ & 1)){
            if(A&1){
                A--;
            }
            B+= A/2;
            A/=2;
        }
        else{
            if(B & 1){B--;
            }
            A += B/2;
            B/=2;

        }
    }
    cout << A << " " << B << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long K;
    scanf("%lld",&K);
    solve(A, B, K);
    return 0;
}
