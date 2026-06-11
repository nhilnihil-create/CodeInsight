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
    if(n < 105){
        cout << 0 << endl;
        return 0;
    }
    int cnt = 1;
    for(int i=107; i<=n; i=i+2){
        int num_cnt = 0;
        for(int j=1; j<=i; j++){
            if(i % j == 0) num_cnt++;
        }
        if(num_cnt == 8) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
