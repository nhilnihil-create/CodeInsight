#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stdio.h>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <limits.h>
#include <stack>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<double,double> pdd;
typedef long long ll;
const int maxn = 1e6 + 10;
ll sum(ll x){
    ll re = 0;
    while(x > 0){
        re += x % 10;
        x /= 10;
    }
    return re;
}
int main(){
    FAST_IO
    int N;
    cin>>N;
    ll ans = 1,p = 1;
    for(int i = 1; i <= N; i++){
        cout<<ans<<endl;
        ll ans1 = ans + p;
        ll ans2 = ans + p * 10;
        if(ans1 * sum(ans2) <= ans2 * sum(ans1)) ans = ans1;
        else {
            ans = ans2;
            p *= 10;
        }
    }
    return 0;
}
