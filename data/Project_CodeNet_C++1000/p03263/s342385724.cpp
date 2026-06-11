#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    int t[h][w];
    rep(i,h)rep(j,w) cin>>t[i][j];
    queue<pair<int,int>> from,to;
    rep(i,h)rep(j,w-1){
        if(t[i][j]%2==1){
            t[i][j+1]++;
            from.push({i+1,j+1});
            to.push({i+1,j+2});
        }
    }
    rep(i,h-1){
        if(t[i][w-1]%2==1){
            t[i+1][w-1]++;
            from.push({i+1,w});
            to.push({i+2,w});
        }
    }
    int res=from.size();
    cout<<res<<endl;
    rep(i,res){
        auto p1=from.front(),p2=to.front();from.pop();to.pop();
        cout<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<endl;
    }
}
