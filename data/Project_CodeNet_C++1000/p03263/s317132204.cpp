//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};

using T=tuple<int,int,int,int>;

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int h,w;
    cin>>h>>w;
    vector<vector<int>> f(h,vector<int>(w,0));
    rep(i,h)rep(j,w) cin>>f[i][j];
    queue<T> ans;
    bool fl=0;
    int x,y,z,zz;
    rep(i,h)rep(j,w-1){
        fl=(f[i][j]%2==1);
        if(!fl) continue;
        ans.emplace(i+1,j+1,i+1,j+2);
        f[i][j+1] ++;
        f[i][j] --;
    }
    rep(i,h-1){
        fl=(f[i][w-1]%2==1);
        if(!fl) continue;
        ans.emplace(i+1,w,i+2,w);
        f[i+1][w-1] ++;
        f[i][w-1] --;
    }
    cout<<ans.size()<<'\n';
    while(!ans.empty()){
        tie(x,y,z,zz)=ans.front();
        ans.pop();
        cout<<x<<" "<<y<<" "<<z<<" "<<zz<<'\n';
    }
    // tie(x,y,z,zz)=ans.front();
    // cout<<x<<" "<<y<<" "<<z<<" "<<zz<<'\n';
    
}