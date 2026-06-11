#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    ll min_num = min({a, b, c, d, e});
    ll times = (n%min_num==0) ? n/min_num : n/min_num+1;
    cout << times + 4 << endl;
}
