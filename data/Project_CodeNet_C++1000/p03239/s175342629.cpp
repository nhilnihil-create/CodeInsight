#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> CT(N);
    for(int i =0 ; i < N; i++) cin >> CT[i].fi >> CT[i].se;
    int min_c = 10000000;
    for(auto p : CT){
        if(p.se <= T) min_c = min(min_c, p.fi);
    }
    if(min_c == 10000000) puts("TLE");
    else cout << min_c << endl;
}
