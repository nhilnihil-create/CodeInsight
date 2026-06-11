#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

ll GCD(ll a, ll b){
    if(b == 0) return a;
    return GCD(b, a % b);
}

int main(){
    int N;
    ll X;
    cin >> N >> X;
    int x[N];
    rep(i, N) cin >> x[i];
    rep(i, N){
        x[i] -= X;
        x[i] = fabs(x[i]);
    }
    ll g = x[0];
    rep(i, N){
        g = GCD(g, x[i]);
    }
    cout << g << endl;
    return 0;
}