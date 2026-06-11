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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    int cnt = 0;
    while(1){
        rep(i, n){
            if(a[i] % 2 == 0){
                a[i] /= 2;
            }else{
                cout << cnt << endl;
                return 0;
            }
        }
        cnt++;
    }

    return 0;
}
