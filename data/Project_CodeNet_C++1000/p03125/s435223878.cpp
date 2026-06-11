#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG

int A,B;
int f(int x,int y){
    if(y%x==0)return x+y;
    else return y-x;
}

signed main(){
    cin>>A>>B;
    cout<<f(A,B)<<endl;
}
