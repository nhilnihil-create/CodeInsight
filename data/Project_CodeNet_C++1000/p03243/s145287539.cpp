#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define rep(i, n) for(int i=0; i<n; ++i)
#define REP(i, n) for(int i=1; i<=n; ++i)
#define all(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
const int inf = 1e9;
const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    int n; cin >> n;
    int candidate[10] = {111, 222, 333, 444, 555, 666, 777, 888, 999, 1111};
    rep(i, 10){
        if(candidate[i] >= n){
            cout << candidate[i] << endl;
            return 0;
        }
    }
}