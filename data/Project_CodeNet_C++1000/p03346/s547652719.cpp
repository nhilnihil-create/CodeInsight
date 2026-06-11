#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)

using namespace std;

int main() {
    ll N;
    cin >> N;
    ll P[N];
    rep(i,N){
        cin >> P[i];
        P[i] --;
    }
    ll Q[N];
    rep(i,N){
        Q[P[i]] = i;
    }
    ll maxConti = 0;
    ll tmp = 1;
    rep(i,N-1){
        if(Q[i] < Q[i + 1]){
            tmp++;
        }else{
            maxConti = max(maxConti,tmp);
            tmp = 1;
        }
    }
    maxConti = max(maxConti,tmp);
    cout << N - maxConti << endl;

}