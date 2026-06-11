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
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265359

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(rall(a));
    int alice = 0;
    int bob = 0;
    rep(i, n){
        if(i % 2  == 0){
            alice += a[i];
        }else{
            bob += a[i];
        }
    }
    cout << alice - bob << endl;
    return 0;
}
