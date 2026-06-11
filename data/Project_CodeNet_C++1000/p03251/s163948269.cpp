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
    int n, m, x, y; cin >> n >> m;
    vector<int>xi(n+1);
    vector<int>yi(m+1);
    cin >> xi[0];
    cin >> yi[0];
    repr(i, 1, n+1) cin >> xi[i];
    repr(i, 1, m+1) cin >> yi[i];

    sort(all(xi));
    sort(all(yi));

    if(xi[n] >= yi[0]){
        cout << "War" << endl;
    }else{
        cout << "No War" << endl;
    }
    
    return 0;
}
