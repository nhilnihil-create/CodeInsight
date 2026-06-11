
//GCD FREQUENCY COUNTER WITH INC-EXC BY ADANCITO

//WHAT DOES THIS ALGORITHM DO?
/*
 
 imagine that for every ordered pair (i, j), 0 <= i, j <= maxN, we did
 res[gcd(i, j)] += one[i] * two[j]
 
 this algorithm calculates the final value of res in O(nlgn)
 
 remember to call precalculations() at the beginning of the program
 
 */

#include <iostream>
#include <string.h>
#include <ctime>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <vector>
#define se second
#define fi first

using namespace std;
const int maxN = 1e5 + 8, MOD = 1e9 + 7;

typedef long long ll;
typedef pair<ll, ll> ii;

int n, arr[maxN], sorted[maxN];

int T[maxN << 2];

int cnd;
void update(int w, int x){
    w += cnd;
    while(w){
        T[w] += x;
        w >>= 1;
    }
}

int query(int l, int r){
    int ret = 0;
    for(l += cnd, r += cnd; l < r; l >>= 1, r >>= 1){
        if(l & 1) ret += T[l++];
        if(r & 1) ret += T[--r];
    }
    return ret;
}

ll eval(ll m){
    memset(T, 0, sizeof T);
    cnd = n * 3 + 6;
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
        int vl = 1;
        if(arr[i] < m) vl = -1;
        update(0, 1);
        cnd -= vl;
        
        
        ans += query(-n, 0);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i]; sorted[i] = arr[i];
    }
    
    sort(sorted, sorted + n);
    
    ll lim = ll(n) * ll(n + 1) >> 2, l = 0, m, r = n;
    
    //cout << lim << '\n';
    
    while(l + 1 < r){
        m = (l + r) >> 1;
        if(eval(sorted[m]) <= lim){//a huevo!, tirale a mas
            l = m;
        }
        else{//te mamaste, bajale de huevos
            r = m;
        }
    }
    
    cout << sorted[l] << '\n';
    
}

//99999000001
//00000999999
