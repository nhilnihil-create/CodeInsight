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
int h,w;
string s[60];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool dfs(int sx, int sy){
    bool ok =  0;
    rep(i,4){
        int nx = sx + dx[i], ny = sy + dy[i];
        if(nx<h && nx>=0 && ny<w && ny>=0){
            if(s[nx][ny]=='#') ok = 1;
        }
    }
    return ok;
}
int main(){
    cin >> h >> w;
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#'){
                if(dfs(i,j)==0){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}