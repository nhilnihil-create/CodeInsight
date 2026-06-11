#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),1);

    bool allok = true;
    vector<int> ans(n,-1);
    rep(i,n){
        bool ok = false;
        for(int j=n-1;j>=0;j--){
            if(ord[j]==b[j]){
                ans[i] = ord[j];
                ord[j] = -1;
                ok = true;
                for(int k=j+1;k<n;k++){
                    ord[k]--;
                }
                break;
            }
        }
        if(!ok){
            allok = false;
            break;
        }
    }

    if(allok){
        rep(i,n) cout << ans[n-i-1] << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}