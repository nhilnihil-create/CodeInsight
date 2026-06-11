#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

int main(){
    int n,m; cin >> n >> m;
    if(n>=m){
        cout << 0 << endl;
        return 0;
    }
    else{
        vector<int> X(m);
        for(int i=0; i<m; i++) cin >> X[i];
        sort(X.begin(), X.end());
        if(n==1) cout << X[m-1] - X[0] << endl;
        else{
            vector<int> dis(m-1);
            for(int i=0; i<m-1; i++){
                dis[i] = X[i+1] -X[i];
            }
            sort(dis.begin(), dis.end());
            ll ans = X[m-1] - X[0];
            for(int i=0; i<n-1; i++) ans -= dis[m-2-i];
            cout << ans << endl;
        }
    }
}