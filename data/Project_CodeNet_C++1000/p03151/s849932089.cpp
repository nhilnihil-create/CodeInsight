#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int> A(N),B(N);
    rep(n,0,N) cin>>A.at(n);
    rep(n,0,N) cin>>B.at(n);

    int ans=0;
    int64_t sumDiff=0;
    vector<int> plusDiff;
    rep(n,0,N){
        int diff=A.at(n)-B.at(n);
        if(diff<0){
            sumDiff+=abs(diff);
            ans++;
        }else if(diff>0){
            plusDiff.push_back(diff);
        }
    }

    sort(ToEnd(plusDiff));
    int64_t sum=0;
    _rep(i,plusDiff.size()-1,0){
        if(sum>=sumDiff) break;
        ans++;
        sum+=plusDiff.at(i);
    }
    if(sum<sumDiff) ans=-1;

    cout<<ans<<endl;
}