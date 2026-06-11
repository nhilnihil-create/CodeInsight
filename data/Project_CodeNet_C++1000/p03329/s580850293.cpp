#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;

    vector<int64_t> Dp(N+1,1e6);
    Dp.front()=0;

    rep(i,0,N){
        if(i+1<N+1) Dp.at(i+1)=min(Dp.at(i+1),Dp.at(i)+1);

        int n=6;
        while(n<N+1){
            if(i+n<N+1) Dp.at(i+n)=min(Dp.at(i+n),Dp.at(i)+1);
            n*=6;
        }

        n=9;
        while(n<N+1){
            if(i+n<N+1) Dp.at(i+n)=min(Dp.at(i+n),Dp.at(i)+1);
            n*=9;
        }
    }

    cout<<Dp.at(N)<<endl;
}