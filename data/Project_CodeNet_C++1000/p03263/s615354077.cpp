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
    ll h,w;cin>>h>>w;
    ll t[h][w];
    rep(i,h)rep(j,w){
        cin>>t[i][j];
        t[i][j]%=2;
    }
    queue<pair<int,int>> p1,p2;
    vector<bool> used(h,false);
    ll res=0;
    rep(i,h-1){
        rep(j,w){
            if(t[i][j]%2==1){
                t[i+1][j]++;
                p1.push({i+1,j+1});
                p2.push({i+2,j+1});
                res++;
            }
        }
    }
    rep(i,w-1){
        if(t[h-1][i]%2==1){
            t[h-1][i+1]++;
            p1.push({h,i+1});
            p2.push({h,i+2});
            res++;
        }
    }
    cout<<res<<endl;
    rep(i,res){
        auto F=p1.front(),T=p2.front();p1.pop();p2.pop();
        cout<<F.first<<" "<<F.second<<" "<<T.first<<" "<<T.second<<endl;
    }
}