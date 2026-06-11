#include <bits/stdc++.h>
using namespace std;
int n,m;
struct A{
    int u,v,d;
};
queue<A> Q;
int cnt;
vector<int> a[21];

void dfs(int v){
    if(v==20)cnt++;
    for(auto &u:a[v])dfs(u);
}
int main(){
    cin>>m;
    int i;
    m--;

    for(i=1 ; (1<<i)-1<m ; i++){
        Q.push({i,i+1,(1<<(i-1))});
        Q.push({i,i+1,0});
       // cout<<i<<" "<<i+1<<" "<<(1<<(i-1))<<"\n";
       //  cout<<i<<" "<<i+1<<" "<<0<<"\n";
    }
    for(i=1 ; i<20 ; i++){
        if(((1<<(i-1))&m)){
            Q.push({i,20,((m>>i)<<i)});
          ///  cout<<i<<" "<<20<<" "<<((m>>i)<<i)<<"\n";
        }
    }
    Q.push({1,20,m});
    cout<<20<<" "<<Q.size()<<"\n";
    while(!Q.empty()){
        A t=Q.front();
        cout<<t.u<<" "<<t.v<<" "<<t.d<<"\n";
        Q.pop();
        a[t.u].push_back(t.v);
    }
   /// dfs(1);
  ///  cout<<cnt;
    return 0;
}
