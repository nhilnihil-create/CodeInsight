#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define mp make_pair
const int MOD=1e9+7;
const int INF=1e15;

int myf(int x,int d){
    if(x%d==0)return x/d;
    else return x/d+1;
}

signed main(){
    int N,H;cin>>N>>H;
    vector<pair<int,int>>A(2*N);
    REP(i,2*N){
        int a;cin>>a;
        if(i%2==0)A[i]=mp(a,0);
        else A[i]=mp(a,1);
    }
    sort(A.rbegin(),A.rend());
    int ans=0;
    int i=0;
    while(H>0){
        if(A[i].second==0){
            ans+=myf(H,A[i].first);
            break;
        }
        else{
            H-=A[i].first;
            ans++;
            i++;
        }
    }
    cout<<ans<<endl;
}
