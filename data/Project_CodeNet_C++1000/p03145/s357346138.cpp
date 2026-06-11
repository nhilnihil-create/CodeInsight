#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1000000;
#include <map>
#include <math.h>
 
using ll = long long;
using namespace std;

ll n, k;
const ll mod = 1000000007;



int main(){
    float a, b, c, max_, square=1;
    cin >> a >> b >> c;
    max_ = max({a, b, c});
    if(a!=max_) square*=a;
    if(b!=max_) square*=b;
    if(c!=max_) square*=c;
    out(square/2);
}