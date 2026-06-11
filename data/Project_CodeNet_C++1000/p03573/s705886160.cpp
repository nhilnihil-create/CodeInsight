#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define _GLIBCXX_DEBUG
const int INF=1e18;

signed main(){
  	int A,B,C;cin>>A>>B>>C;
    if(A==B)cout<<C<<endl;
    else{
        if(A==C)cout<<B<<endl;
        else cout<<A<<endl;
    }
}