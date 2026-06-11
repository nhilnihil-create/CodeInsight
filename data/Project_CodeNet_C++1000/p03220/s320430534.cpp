#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using P = pair<int,int>;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//struct area

//function area

//main area
int main(){
    int n, t, a;
    cin >> n >> t >> a;
    t *= 1e3, a *= 1e3;
    int h[n];
    int ans = 1e9;
    rep(i, n){
        cin >> h[i];
        ans = min(ans, abs(t - h[i]*6 - a));
    }
    rep(i, n){
        if(abs(t - h[i]*6 - a) == ans){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}
/*

平均気温 - a の絶対値の最小値を記録しておいて
あとでどこだったのか確認すればオーケー？
pairでsortだとO(NlogN)だけど、
これならO(N)なので実はこっちのほうが早い

*/