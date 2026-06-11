#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF 1000000000
#define MOD 1000000007


int main(){
    ll N, P; cin >> N >> P;
    if(N==1){
        cout << P << endl;
        return 0;
    }

    ll ans = 1;
    for(ll i=1; pow(i, N)<=P; i++){
        if(P%(ll)pow(i,N)==0) ans = i;
    }
    cout << ans << endl;
    return 0;
}
