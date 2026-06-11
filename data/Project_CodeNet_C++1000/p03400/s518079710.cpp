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
    int d, x; cin >> d >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int result = 0;
    // 1, a+1, 2a+1, 
    rep(i,n){
        rep(j, d+1){
            if(1+j*a[i] <= d){
                result++;
            }else{
                break;
            }
        }
    }

    cout << result + x << endl;

    return 0;
}
