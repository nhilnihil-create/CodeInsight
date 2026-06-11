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
    int a[1000007] = {};
    int cnt[1000007] = {};
    int s; cin >> s;
    a[0] = s;
    cnt[s]++;
    int ans = -1;

    repr(i, 1, 1000001){
        if(a[i-1] % 2 == 0){
            a[i] = a[i-1] / 2;
            cnt[a[i]]++;
        }else{
            a[i] = 3*a[i-1] + 1;
            cnt[a[i]]++;
        }
        if(cnt[a[i]] == 2){
            ans = i+1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
