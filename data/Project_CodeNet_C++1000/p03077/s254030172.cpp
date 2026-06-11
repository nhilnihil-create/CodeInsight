#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const ll MOD = 1e+9+7;

int main(){
    ll N,A,B,C,D,E;
    cin>>N>>A>>B>>C>>D>>E;
    ll L=min(A,B);
    L=min(L,C);
    L=min(L,D);
    L=min(L,E);
    ll ans=4;
    ans+=N/L;
    if(N%L!=0){
        ans++;
    }
    cout<<ans<<endl;


    
}