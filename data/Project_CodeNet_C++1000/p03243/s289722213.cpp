#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int N;cin>>N;
    for(int i=1;i<=9;i++){
        if(111*i-N>=0){
            cout<<111*i<<endl;
            break;
        }
    }
}