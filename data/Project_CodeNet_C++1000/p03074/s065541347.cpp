#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N,K;
    cin>>N>>K;
    string S;
    cin>>S;
    vector<P> rev(0);
    int from=-1,to=-1;
    rep(i,N){
        if(S.at(i)=='0'){
            if(to>=0){
                rev.pb({from,to});
                from=-1,to=-1;
            }
        }
        else{
            if(from>=0){
                to=i;
            }
            else{from=i,to=i;}
        }
    }
    if(from>=0){
        rev.pb({from,N-1});
    }
    /*rep(i,rev.size()){
        cout<<rev.at(i).first<<","<<rev.at(i).second<<" ";
    }*/
    int x=rev.size();
    if(K>x){cout<<N<<endl;return 0;}
    int ans=rev.at(K-1).second+1;
    chmax(ans,N-rev.at(x-K).first);
    for(int i=1;K-1+i<x;i++){
        chmax(ans,rev.at(K-1+i).second-rev.at(i-1).first+1);
    }
    cout<<ans<<endl;
}