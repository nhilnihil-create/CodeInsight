#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,m; cin >> n >> m;
    
    vi fav(m, 0);
    rep(i,n){
        int k;cin>>k;
        rep(j,k){
            int a;cin>>a;
            a--;fav[a]++;
        }
    }
    
    int ans = 0;
    rep(i,m)if(fav[i]==n)ans++;
    cout << ans << endl;
    
    return 0;
}