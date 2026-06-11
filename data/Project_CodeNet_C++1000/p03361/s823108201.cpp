//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int h,w; cin>>h>>w;
    string ans="Yes";
    vector<vector<char>> m(h+2,vector<char>(w+2,'.'));
    vector<vector<int>> d={{1,0},{-1,0},{0,1},{0,-1}};
    rep(i,h)rep(j,w){
        cin>>m[i+1][j+1];
    }
    rep(i,h)rep(j,w){
        if(m[i+1][j+1]=='.') continue;
        int cnt=0,dx,dy;
        for(auto c:d){
            dx=c[0]; dy=c[1];
            if(m[i+1+dx][j+1+dy]=='.') cnt++;
        }
        if(cnt==4){
            ans="No";
        }
    }
    cout<<ans<<endl;
}