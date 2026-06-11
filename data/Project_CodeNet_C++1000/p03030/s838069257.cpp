#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long

signed main(){
    int N;
    cin >>N;
    vector<tuple<string,int,int>>vec(N);
    REP(i,N){
        string S;
        int P;
        cin>>S>>P;
        vec[i]=make_tuple(S,-P,i+1);
    }
    sort(vec.begin(),vec.end());
    REP(i,N){
        int t=get<2>(vec[i]);
        cout<<t<<endl;
    }
}
