#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define pb push_back
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    int A,B;cin>>A>>B;A--;
    int aans=0;
  	if(A<0)A=0;
    if(A%2==1){
        if(A%4==1)aans++;
    }
    else{
        if(A%4==0)aans+=A;
        else aans+=(1 ^ A);
    }
    int bans=0;
    if(B%2==1){
        if(B%4==1)bans++;
    }
    else{
        if(B%4==0)bans+=B;
        else bans+=(1 ^ B);
    }
    cout<<(aans ^ bans)<<endl;
}
