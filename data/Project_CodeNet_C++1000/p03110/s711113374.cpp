#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/*

 * */

int main() {
    int N;
    cin >> N;

    double x[N];
    string u[N];
    rep(i, N){
        cin >> x[i] >> u[i];
    }

    double ans = 0;
    rep(i,N){
        if(u[i] == "JPY"){
            ans += x[i];
        }else{
            ans += x[i] * 380000.0;
        }
    }
    cout << ans << endl;
    return 0;
}
