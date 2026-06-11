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
    int n,m;cin>>n>>m;
    vector<pair<int,int>> p(m);
    map<int,int> mp1;
    vector<vector<int>> x(n+10);
    int tmp=1;
    rep(i,m){
        int a,b;cin>>a>>b;
        p[i]={a,b};
        if(mp1[a]==0){
            mp1[a]=tmp;
            x[tmp].push_back(b);
            tmp++;
        }else{
            int y=mp1[a];
            x[y].push_back(b);
        }
    }
    rep(i,tmp){
        auto& c=x[i];
        sort(c.begin(),c.end());
    }
    rep(i,m){
        int a=p[i].first,b=p[i].second;
        string P=to_string(a), Y;
        while(P.size()<6) P="0"+P;
        auto t=mp1[a];
        auto itr= lower_bound(x[t].begin(),x[t].end(),b);
        Y=to_string((int)(itr-x[t].begin())+1);
        while(Y.size()<6) Y="0"+Y;
        cout<<P<<Y<<endl;
    }
}