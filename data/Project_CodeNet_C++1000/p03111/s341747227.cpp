#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define mp make_pair
#define _GLIBCXX_DEBUG
const int INF=1e15;
int N,A,B,C;
vector<int>L(8);

int dfs(int a,int b,int c,int i){
    if(i==N){
        if(min(a,min(b,c))!=0) return abs(a-A)+abs(b-B)+abs(c-C);
        else return INF;
    }
    int a1=dfs(a,b,c,i+1);
    int a2=dfs(a+L[i],b,c,i+1)+10;
  	if(a==0) a2-=10;
    int a3=dfs(a,b+L[i],c,i+1)+10;
  	if(b==0) a3-=10;
    int a4=dfs(a,b,c+L[i],i+1)+10;
  	if(c==0) a4-=10;
    return min(min(a1,a2),min(a3,a4));
}

signed main(){
    cin>>N>>A>>B>>C;
    REP(i,N)cin>>L[i];
    cout<<dfs(0,0,0,0)<<endl;
}