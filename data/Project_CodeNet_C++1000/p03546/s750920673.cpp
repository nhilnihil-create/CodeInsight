#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int H,W; cin>>H>>W;
    vector<vector<int>> C(10,vector<int>(10));
    rep(i,0,10)rep(j,0,10) cin>>C.at(i).at(j);
    vector<int> Cnt(10,0);
    rep(h,0,H)rep(w,0,W){
        int n; cin>>n;
        if(n>=0 && n<10 && n!=1) Cnt.at(n)++;
    }

    queue<int> q;
    q.push(1);
    vector<int> Cost(10,INT_MAX);
    Cost.at(1)=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        rep(i,0,10){
            int c=C.at(i).at(node),_cost=Cost.at(node)+c;
            if(_cost<Cost.at(i)){
                Cost.at(i)=_cost;
                q.push(i);
            }
        }
    }

    int ans=0;
    rep(i,0,10){
        ans+=Cnt.at(i)*Cost.at(i);
    }

    cout<<ans<<endl;
}