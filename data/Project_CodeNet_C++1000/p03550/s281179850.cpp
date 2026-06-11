#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;

int main()
{
    int n; cin >> n;
    ll z,w; cin >> z >> w;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << abs(w-a[0]);
    }else{
        ll ans = 0;
        if(abs(a[n-2] - a[n-1]) > abs(a[n-1] - w)) {
            ans = abs(a[n-2] - a[n-1]);
        }else{
            ans = abs(a[n-1] - w);
        }
        cout << ans << endl;
    }
}