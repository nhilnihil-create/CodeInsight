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
    int k; cin >> k;
    int result = 1;
    rep(i, n){
        if(result*2 < result+k){
            result *= 2;
        }else{
            result += k;
        }
    }
    cout << result << endl;
    return 0;
}
