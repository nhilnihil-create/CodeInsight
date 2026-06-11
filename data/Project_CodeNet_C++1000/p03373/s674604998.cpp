#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
#include <map>
#include <math.h>

using ll = long long;
using namespace std;

int main(){
    ll a, b, c , X, Y;
    cin >> a >> b >> c >> X >> Y;
    
    ll count=INF;
    rep(i, max(X, Y)+1){
       ll x = max(0LL, X-i);
       ll y = max(0LL, Y-i);
       ll d; d= c*2*i + x*a + y*b;
       if (count>d) count = d;
    }
    cout << count << endl;

}

