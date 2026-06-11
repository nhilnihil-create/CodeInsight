#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    vector<vector<int>> t(h,vector<int>(w));
    rep(i,h)rep(j,w) cin>>t[i][j];
    vector<pair<int,int>> p,p2;
    rep(i,h){
        rep(j,w-1){
            if(t[i][j]%2==1){
                p.push_back({i+1,j+1});
                p2.push_back({i+1,j+2});
                t[i][j+1]++;
            }
        }
        if(i==h-1) break;
        if(t[i][w-1]%2==1){
            p.push_back({i+1,w});
            p2.push_back({i+2,w});
            t[i+1][w-1]++;
        }
    }
    cout<<p.size()<<endl;
    rep(i,p.size()){
        cout<<p[i].first<<" "<<p[i].second<<" "<<p2[i].first<<" "<<p2[i].second<<endl;
    }
}