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
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    int count;
    count = 10*a[2]+a[1]+a[0];
    out(count);
}