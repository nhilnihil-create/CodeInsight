#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (int)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N,K; cin>>N>>K;
    string S; cin>>S;
    vector<int> A;
    if(S.at(0)=='0')A.push_back(0);//A.at(odd)は1のnum
    A.push_back(1);
    rep1(i,N){
        
        if(S.at(i)!=S.at(i-1))A.push_back(1);
        else{
            A.at(A.size()-1)++;
        }
    }
    int L = A.size();
    // for(auto i:A)cout<<i;
    // cout<<endl;
    
    K = 2*K+1;
    int res = 0, tmp = 0;
    rep(i,min(K,(int)A.size()))tmp+=A.at(i);
    res = tmp;
    // cout<<res<<endl;
    
    // cout<<L<<K<<endl;
    for(int i = 2; i <= L; i += 2){
        
        tmp = tmp - A.at(i-1) - A.at(i-2);
        if(K-2+i<L)tmp += A.at(K-2+i);
        if(K+i-1<L)tmp += A.at(K-1+i);
        // cout<<tmp<<i<<endl;
        res = max(res,tmp);
    }
    cout<<res<<endl;
}