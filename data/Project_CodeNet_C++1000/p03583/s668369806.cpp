//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;

LL h,n,w;

void solve(){
    for(h=1;h<=3500;h++){
        for(n=h;n<=3500;n++){
            LL a = 4*h*n - N*(n+h);
            if(a<=0) continue;
            LL b = N*h*n;
            if(b%a==0){
                w = b/a;
                //printf("%lld %lld %lld\n",h,n,w);
                return;
            }
        }
    }
}
 
int main(){
    cin >> N;
 
    solve();

    cout << h << " " << n << " " << w << endl;
    return 0;
}