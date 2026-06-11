#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,H; cin>>N>>H;
    priority_queue<int> A;
    vector<int> B(N);
    rep(n,0,N){
        int a,b; cin>>a>>b;
        A.push(a);
        B.at(n)=b;
    }

    sort(ToEnd(B));
    int64_t ans=0;
    _rep(i,N-1,0){
        if(B.at(i)>A.top()){
            H-=B.at(i);
            ans++;
            if(H<=0) break;
        }else{
            break;
        }
    }

    if(H>0) ans+=ceil((double)H/A.top());
    cout<<ans<<endl;
}