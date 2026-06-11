#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <set>
#include <utility>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
typedef pair<string, int> P;
typedef long long ll;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
const int MAXN = 100000;
const int MAXE = 100000;
const int MAXV = 10000;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n){
        for(int i=0;i<n;++i) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[ry]>rank[rx]) par[rx]=ry;
        else par[ry]=rx;
        if(rank[rx]==rank[ry]) rank[rx]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
};

int main(){
    string s;cin>>s;
    int x,y;cin>>x>>y;
    vector<int> f,fx,fy;
    int cnt=0;
    for(int i=0;i<(int)s.size();++i){
        if(s[i]=='F') cnt++;
        else{
            f.push_back(cnt);
            cnt=0;
        }
    }
    if(cnt>0) f.push_back(cnt);
    for(int i=0;i<(int)f.size();++i){
        if(i%2==0) fx.push_back(f[i]);
        else fy.push_back(f[i]);
    }
    int n=(int)fx.size(),m=(int)fy.size();
    vector<vector<bool> > dpx(n+1,vector<bool>(16005,false)),dpy(m+1,vector<bool>(16005,false));
    dpx[0][8000]=true;dpy[0][8000]=true;
    for(int i=0;i<n;++i){
        for(int j=0;j<=16000;++j){
            if(dpx[i][j]){
                if(i==0) dpx[i+1][j+fx[i]]=true;
                else dpx[i+1][j+fx[i]]=dpx[i+1][j-fx[i]]=true;
            }
        }
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<=16000;++j){
            if(dpy[i][j]){
                dpy[i+1][j+fy[i]]=dpy[i+1][j-fy[i]]=true;
            }
        }
    }
    if(dpx[n][8000+x]&&dpy[m][8000+y]){
        cout<<"Yes"<<endl;
    }else cout<<"No"<<endl;
    return 0;
}