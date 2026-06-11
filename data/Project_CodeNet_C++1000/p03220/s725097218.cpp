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
    int N; cin >> N;
    int T, A; cin >> T >> A;
    vector<int> H(N);

    int ans;
    int diff = 1000000000;
    rep(i, N){
        cin >> H[i];
        int tmp = abs((T*1000-H[i]*6) -  A*1000);
        if(tmp < diff){
            ans = i+1;
            diff = tmp;
        }
    }

    cout << ans << endl;

    return 0;
}
