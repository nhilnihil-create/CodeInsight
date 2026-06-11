#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N;
    cin >> N;
    VL t(N+1), x(N+1), y(N+1);
    x[0] = 0; y[0] = 0; t[0] = 0;
    rep(i, 1, N+1) cin >> t[i] >> x[i] >> y[i];
    rep(i, 0, N){ // ?
        ll diff = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
        if(diff > t[i+1] - t[i] || diff % 2 != (t[i+1] - t[i]) % 2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
