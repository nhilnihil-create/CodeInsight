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
    vector<int> V(n);
    vector<int> C(n);

    rep(i,n) cin >> V[i];
    rep(i,n) cin >> C[i];

    int value = 0;
    int cost = 0;

    rep(i,n){
        if(V[i] > C[i]){
            value += V[i];
            cost += C[i];
        }
    }

    cout << value - cost << endl;

    return 0;
}
