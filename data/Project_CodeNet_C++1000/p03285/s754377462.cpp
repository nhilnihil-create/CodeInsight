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
    bool flg=false;
    if(n % 4 == 0) flg=true;
    if(n % 7 == 0) flg=true;
    if(n % 11 == 0) flg=true;
    rep(i, n/4+1){
        rep(j, n/7+1){
            if(4*i+7*j == n) flg = true;
        }
    }

    if(flg){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
