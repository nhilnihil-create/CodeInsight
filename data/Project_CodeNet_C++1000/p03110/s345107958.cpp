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
    int N;
    cin >> N;
    vector<pair<double, string>> xu(N);
    for(int i = 0; i < N; i++) cin >> xu[i].fi >> xu[i].se;
    double sum = 0;
    for(int i = 0; i < N; i++){
        if(xu[i].se == "BTC") sum += xu[i].fi * 380000.0;
        else sum += xu[i].fi;
    }
    cout << sum << setprecision(8) << endl;
}
