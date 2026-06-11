#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
 
signed main(){
    int K,A,B;cin>>K>>A>>B;
    int bis=1;
    if(K<=A||B-A<=2)cout<<K+1<<endl;
    else{
        bis=A-1;
      	K-=(A-1-1);
      	K-=3;
      	bis=B;
      	int d=K/2;
      	bis+=d*(B-A);
      	if(K%2==1)bis++;
      	cout<<bis<<endl;
    }   
}