#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    ll x,y;
    cin >> x >> y;
    if(x % y == 0){
        cout << -1 << endl;
    }else{
        cout << x << endl;
    }
}