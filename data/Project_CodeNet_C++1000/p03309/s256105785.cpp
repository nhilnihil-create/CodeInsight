#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const ll INF = 1e+18;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    ll tmp;
    rep(i,N){
        cin >> tmp;
        A[i]=tmp - (i+1);
    }
    sort(A.begin(),A.end());
    vector<ll> d(N);
    
    d[0]=0;
    rep(i,N){
        d[0]+=(A[i]-A[0]);
    }

    ll ans=d[0];
    rep(i,N-1){
        d[i+1]=d[i]-(A[i+1]-A[i])*(N-2*(i+1));
        ans=min(ans,d[i+1]);
    }
    cout << ans << endl;

    
}
