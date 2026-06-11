#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(Array) sort(Array.begin(), Array.end())
#define rev(a) reverse(a.begin(), a.end())
#define out(ans) cout << ans << endl;
const int MOD = 1000000007;
const int INF = INT_MAX;

//------------↓------------- M -------------- E ---------------- M --------------- O ---------------↓--------------//
// コンパイル 
// g++ -std=c++1z
//
// -------型変換--------
// int を string に変換
// string s = to_string(n);
// string を int に変換
// int n = stoi(s);
//
// -------二分探索---------
// k以上の値が最初に現れる時のイテレータ O(logN)
// lower_bound(data.begin(), data.end(), k)
// kより大きい値が最初の現れる時のイテレータ O(logN)
// upper_bound(data.begin(), data.end(), k)
// kがdataに存在するかをtrue or falseで返す O(logN)
// binary_search(data.begin(), data.end(), k)
// 
//
//
//
//
//
// 
//------------↑------------- M -------------- E ---------------- M --------------- O ---------------↑--------------//



int main() {

    ll n;
    cin >> n;
    vector <ll> a(n);
    rep(i,n) cin >> a[i];

    ll sum = max(a[0], -a[0]);
    rep(i,n-1) sum += max(a[i+1] - a[i], a[i] - a[i+1]);
    sum += max(a[n-1], -a[n-1]);

    vector <ll> ans(n);
    rep(i,n) ans[i];
    rep(i,n) {
        if (i == 0) ans[i] = sum - max(a[0], -a[0]) - max(a[1]-a[0], a[0]-a[1]) + max(a[1], - a[1]);
        else if (i == n - 1) ans[i] = sum - max(a[n-1], -a[n-1]) - max(a[n-1]-a[n-2], a[n-2]-a[n-1]) + max(a[n-2], -a[n-2]);
        else ans[i] = sum - max(a[i]-a[i-1], a[i-1]-a[i]) - max(a[i]-a[i+1], a[i+1]-a[i]) + max(a[i+1]-a[i-1], a[i-1]-a[i+1]);
    }

    rep(i,n) out(ans[i]);

    return 0;
}






