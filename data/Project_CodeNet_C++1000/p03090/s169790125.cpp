#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int N;cin>>N;
    vector<pair<int,int>> edge;
    rep(i,1,N+1){
        rep(j,i+1,N+1) if(j!=((N%2==1)?N-i:N+1-i)){
            edge.push_back({i,j});
        }
    }
    cout<<edge.size()<<endl;
    for(auto e:edge){
        cout<<e.first<<" "<<e.second<<endl;
    }
}
