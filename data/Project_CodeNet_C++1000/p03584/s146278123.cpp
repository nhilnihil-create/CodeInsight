#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>
#include <utility>
#include <stack>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    ll N, K, a[101000], b[101000];
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
    }

    ll res = 0;
    for(int i = 29; i >= 0; i--){
        if((K >> i) % 2 == 0){
            continue;
        }
        ll K2 = ((K >> (i+1)) << 1);   // 上位桁
        ll resTmp = 0;
        for(int j = 0; j < N; j++){
            if((K2 | (a[j] >> i)) == K2){
                resTmp += b[j];
            }
        }
        res = max(res, resTmp);
    }
    ll resTmp = 0;
    for(int j = 0; j < N; j++){
        if((K | a[j]) == K){
            resTmp += b[j];
        }
    }
    res = max(res, resTmp);
    cout << res << endl;

    return 0;
}