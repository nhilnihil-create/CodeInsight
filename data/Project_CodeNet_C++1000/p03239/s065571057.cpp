#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int N, T;
    cin >> N >> T;
    int ans = INF;
    for(int i = 0; i < N; i++){
        int c, t;
        cin >> c >> t;
        if(T >= t){
            ans = min(ans, c);
        }
    }
    if(ans == INF){
        cout << "TLE" << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}