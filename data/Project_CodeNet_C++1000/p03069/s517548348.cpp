#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
typedef pair<int, int> P;

int main(){
    int n, i, res = 1000000;
    string s;
    cin >> n >> s;
    int cb[n+1] = {}, cw[n+1] = {};
    cb[0] = 0;
    for(i=0; i<n; i++){
        cb[i+1] = cb[i] + (s[i] == '#');
    }
    cw[n] = 0;
    for(i=n; i>0; i--){
        cw[i-1] = cw[i] + (s[i] == '.');
    }
    for(i=0; i<=n; i++){
        res = min(res, cb[i]+cw[i]);
    }
    cout << res << "\n";
    return 0;
}