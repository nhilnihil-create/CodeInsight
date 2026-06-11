#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int N;cin>>N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    if(A[0]>0){
        cout<<-1<<endl;
        return 0;
    }
    ll ans=0;
    for(int i=N-1;i>=0;--i){
        if(A[i-1]+1<A[i]){
            cout<<-1<<endl;
            return 0;
        }
        if(A[i-1]>=A[i]){
            ans+=A[i];
        }
        else{
            ans++;
        }
    }
    cout<<ans<<endl;
}
