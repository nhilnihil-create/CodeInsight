#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int h,w;
    cin >> h >> w;
    vector<vector<int>> cost(10,vector<int>(10,inf));
    rep(i,10){
        rep(j,10) cin >> cost[i][j];
    }
    rep(k,10){
        rep(i,10){
            rep(j,10){
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }
    ll sum = 0;
    rep(i,h) rep(j,w){
        int x;
        cin >> x;
        if(x==-1) continue;
        sum += cost[x][1];
    }
    cout << sum << endl;
    return 0;
}