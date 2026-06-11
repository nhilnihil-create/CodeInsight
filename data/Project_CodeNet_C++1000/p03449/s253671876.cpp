#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(2,vector<int>(n));
    rep(i,2){
        rep(j,n){
            cin >> a.at(i).at(j);
        }
    }
    int ans=0;
    rep(i,n){
        int sum=0;
        rep(j,i+1){
            sum+=a.at(0).at(j);
        }
        for(int k=i;k<n;k++){
            sum+=a.at(1).at(k);
        }
        ans=max(ans,sum);
    }
    cout << ans << endl;
}
