#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main(){
    int N,K;
    cin>>N>>K;
    vector<ll>V(N);
    rep(i,N){
        cin>>V.at(i);
    }
    ll M=0;
    int limit=min(N,K);
    rep(i,limit+1){
        rep(j,limit+1-i){
            vector<ll>get;
            ll sum=0;
            rep(k,i){
                get.push_back(V.at(k));
                sum=sum+V.at(k);
            }
            rep(s,j){
                get.push_back(V.at(N-1-s));
                sum=sum+V.at(N-1-s);
            }
            sort(get.begin(),get.end());
            int l=get.size();
            rep(t,min(l,K-(i+j))){
                if(get.at(t)<0){
                    sum=sum-get.at(t);
                }
            }
            M=max(M,sum);
        }
    }//全探索
    cout<<M<<endl;
}