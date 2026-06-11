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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int count=INF;
    if(a+c<count) count=a+c;
    if(a+d<count) count=a+d;
    if(b+c<count) count=b+c;
    if(b+d<count) count=b+d;
    out(count);
}
