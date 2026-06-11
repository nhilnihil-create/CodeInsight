#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define PI 3.14159265359

int main(){
    int n; cin >> n;
    ll l0 = 2;
    ll l1 = 1;
    if(n == 0){
        cout << l0 << endl;
    }else if(n == 1){
        cout << l1 << endl;
    }else{
        ll t0 = l0;
        ll t1 = l1;
        ll result = t0 + t1;
        repr(i, 2, n+1){
            result = t0 + t1;
            t0 = t1;
            t1 = result;
        }
        cout << result << endl;
    }

    return 0;
}
