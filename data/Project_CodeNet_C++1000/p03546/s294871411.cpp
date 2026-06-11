#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int h,w;
    cin >> h >> w;
    vector<vector<int>> c(10,vector<int>(10));
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,10){
        rep(j,10) cin >> c[i][j];
    }
    rep(i,h){
        rep(j,w) cin >> a[i][j];
    }

    vector<int> cost(10);
    vector<bool> t(10);
    t[1]=true;
    cost[1]=0;

    for(int k=0; k<9; k++){
        int x=mod,p;
        rep(i,10){
            if(t[i]) continue;
            rep(j,10){
                if(!t[j]) continue;
                if(x>c[i][j]+cost[j]){
                    x=c[i][j]+cost[j];
                    p=i;
                }
                // cout << i << ' ' << j << endl;
            }
        }
            t[p]=true;
            cost[p]=x;
    }
    
    ll sum=0;
    rep(i,h){
        rep(j,w){
            if(a[i][j]==-1) continue;
            sum+=cost[a[i][j]];
        }
    }
    cout << sum << endl; 

    return 0;
}