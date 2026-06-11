#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int m;
    ll k;
    cin >> m >> k;
    if(k == 0){
        for(int i = 0; i < pow(2, m); i++){
            cout << i << " " << i << " ";
        }
        cout << endl;
        return 0;
    }
    if(m == 1){
        cout << -1 << endl;
        return 0;
    }
    if(pow(2, m) <= k){
        cout << -1 << endl;
        return 0;
    }
    cout << k << " ";
    for(int i = 0; i < pow(2, m); i++){
        if(i == k) continue;
        cout << i << " ";
    }
    cout << k << " ";
    for(int i = pow(2, m) - 1; i >= 0; i--){
        if(i == k) continue;
        cout << i << " ";
    }
    cout << endl;
    return 0;
}