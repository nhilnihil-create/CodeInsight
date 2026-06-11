#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

vector<int> P(1e5+1,1),sumP(1e5+1,0);
set<int> Prime;

int main(){
    int Q; cin>>Q;
    vector<pair<int,int>> LR;
    rep(q,0,Q){
        int l,r; cin>>l>>r;
        LR.emplace_back(l,r);
    }

    for(int i=2;i<P.size();i++){
        if(P.at(i)){
            Prime.insert(i);
            int k=2;
            while(i*k<P.size()){
                P.at(i*k)=0;
                k++;
            }
        }
    }

    rep(i,2,sumP.size()){
        if(i%2){
            if(Prime.count(i) && Prime.count((i+1)/2)) sumP.at(i)=sumP.at(i-1)+1;
            else sumP.at(i)=sumP.at(i-1);
        }else sumP.at(i)=sumP.at(i-1);
    }

    for(auto lr:LR){
        int ans=sumP.at(lr.second)-sumP.at(lr.first-1);
        cout<<ans<<endl;
    }
}