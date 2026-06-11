#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> where(n);
    rep(i,n){
        int a;
        cin >> a;
        --a;
        where[a] = i;
    }
    int mx = 1;
    int now = 1;
    rep(i,n-1){
        if(where[i] < where[i+1]){
            ++ now;
        }else{
            mx = max(now,mx);
            now = 1;
        }
    }
    mx = max(now,mx);
    cout << n - mx << endl;
    return 0;
}