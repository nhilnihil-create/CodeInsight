#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long

signed main(){
    string S;
    cin>>S;
    string c=S.substr(5,2);
    int a=stoi(c);
    if(a<=4)cout<<"Heisei"<<endl;
    else cout<<"TBD"<<endl;
}