#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N;cin>>N;
    vector<ll> a(N);
    REP(i,N)cin>>a[i];
    int i1=0,i2=0;
    ll m=INF,M=-INF;
    REP(i,N){
        if(a[i]<m){
            m=a[i];
            i1=i;
        }
        if(a[i]>M){
            M=a[i];
            i2=i;
        }
    }
    if(abs(M)>=abs(m)&&M>=0){
        cout<<2*N-1<<endl;
        REP(i,N){
            cout<<i2+1<<" "<<i+1<<endl;
        }
        REP(i,N-1){
            cout<<i+1<<" "<<i+2<<endl;
        }
    }else if(abs(M)>=abs(m)&&M<0){
        cout<<0<<endl;
    }else if(abs(M)<abs(m) && m>=0){
        cout<<0<<endl;
    }else{
        cout<<2*N-1<<endl;
        REP(i,N){
            cout<<i1+1<<" "<<i+1<<endl;
        }
        REP(i,N-1){
            cout<<N-i<<" "<<N-i-1<<endl;
        }
    }
    return 0;
}