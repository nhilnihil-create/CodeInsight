#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

int myf(int x,int y){
  	if(x%y==0) return x/y;
  	else return x/y+1;
}

signed main(){
    int N,K;
    cin>>N>>K;
    cout<<myf(N-1,K-1)<<endl;
}