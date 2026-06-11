#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
const int MOD=1e9+7;
const int INF=1e15;
 
signed main(){
    int N;cin>>N;
    map<int,int>amemo;
    map<int,int>bmemo;
    REP(i,N){
        int v;cin>>v;
        if(i%2==0)amemo[v]++;
        else bmemo[v]++;
    }
    int max1=0;
    int max1v=0;
    int max2=0;
    int max2v=0;
    for(auto it=amemo.begin();it!=amemo.end();it++){
        int d=it->second;
        if(max1<d){
            max1=d;
            max1v=it->first;
        }
    }
  	for(auto it=amemo.begin();it!=amemo.end();it++){
        int d=it->second;
        if(it->first!=max1v&&max2<d){
            max2=d;
          	max2v=it->first;
        }
    }
    int bmax1=0;
    int bmax1v=0;
    int bmax2=0;
    int bmax2v=0;
    for(auto it=bmemo.begin();it!=bmemo.end();it++){
        int d=it->second;
        if(bmax1<d){
            bmax1=d;
            bmax1v=it->first;
        }
    }
  	for(auto it=bmemo.begin();it!=bmemo.end();it++){
        int d=it->second;
        if(it->first!=bmax1v&&bmax2<d){
            bmax2=d;
          	bmax2v=it->first;
        }
    }
  	if(max1v!=bmax1v)cout<<N-max1-bmax1<<endl;
    else cout<<N-max1-max(max2,bmax2)<<endl;
}