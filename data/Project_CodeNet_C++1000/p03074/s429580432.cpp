#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,K; cin>>N>>K;
    string S; cin>>S;
    
    vector<int> V(N,0);
    int idx=0,vIdx=0;
    rep(i,1,N){
        if(S.at(i-1)!=S.at(i)){
            V.at(vIdx)=pow(-1,S.at(i-1)-'0'+1)*(i-idx);

            idx=i;
            vIdx++;
        }
    }
    V.at(vIdx)=pow(-1,S.at(N-1)-'0'+1)*(N-idx);

    vector<int> sumV{0};
    rep(i,1,N+1){
        if(V.at(i-1)==0) break;
        sumV.push_back(sumV.at(i-1)+abs(V.at(i-1)));
    }
    int ans=0;
    for(int i=0;i<sumV.size();i+=2){
        if(V.front()>0){
            ans=max(ans,sumV.at(min((int)sumV.size()-1,2*K+1+i))-sumV.at(i));
        }else{
            ans=max(ans,sumV.at(min((int)sumV.size()-1,2*K+i))-sumV.at(max(0,i-1)));
        }
    }
    cout<<ans<<endl;

}