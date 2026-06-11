#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
int main(void){
    int h,w;cin>>h>>w;
    int c[10][10];
    rep(i,10)rep(j,10) cin>>c[i][j];
    vector<int> t(10,1e+4);
    t[1]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;
    que.push({0,1});
    while(que.size()){
        int k=que.top().first,x=que.top().second;que.pop();
        rep(i,10){
            int nk=k+c[i][x];
            if(chmin(t[i],nk))que.push({nk,i});
        }
    }
    ll res=0;
    rep(i,h)rep(j,w){
        int a;cin>>a;
        if(a==-1)continue;
        res+=t[a];
    }
    cout<<res<<endl;
}