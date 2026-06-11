#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<vector<vector<int>>> F(N,vector<vector<int>>(5,vector<int>(2)));
    rep(i,0,N)rep(j,0,5)rep(k,0,2) cin>>F.at(i).at(j).at(k);
    vector<vector<int64_t>> P(N,vector<int64_t>(11));
    rep(i,0,N)rep(j,0,11) cin>>P.at(i).at(j);

    int64_t ans=INT64_MIN;
    rep(i,1,1<<10){
        bitset<10> b(i);

        vector<int> _P(N,0);
        rep(j,0,10){
            if(b.test(j)){
                rep(k,0,N){
                    if(F.at(k).at(j/2).at(j%2)) _P.at(k)++;
                }
            }
        }

        int64_t _ans=0;
        rep(i,0,N){
            _ans+=P.at(i).at(_P.at(i));
        }
        ans=max(ans,_ans);
    }

    cout<<ans<<endl;
}