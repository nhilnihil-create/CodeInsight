#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main(){
    ll N;
    cin>>N;
    vector<pair<ll,ll>>A(N);
    rep(i,N){
        cin>>A[i].first;
        A[i].second=i;
    }
    vector<ll>B(N);
    sort(A.begin(),A.end());
    rep(i,N){
        if(i<=N/2-1){
            B[A[i].second]=A[N/2].first;
        }
        else{
            B[A[i].second]=A[N/2-1].first;            
        }
    }
    rep(i,N){
        cout<<B[i]<<endl;    
    }
}