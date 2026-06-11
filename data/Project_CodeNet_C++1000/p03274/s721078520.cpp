#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k; cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int ans = 1001001001;
    for(int i = 0; i < n - k + 1; ++i){
        int lid = i;
        int rid = i + k - 1;
        int tmp = 0;
        if(x[rid] <= 0){
            tmp = abs(x[lid]);
        }else if(x[lid]>=0){
            tmp = x[rid];
        }else{
            int time1 = abs(x[lid]) + abs(x[rid] - x[lid]);
            int time2 = x[rid] + abs(x[lid] - x[rid]);
            tmp = min(time1, time2);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}