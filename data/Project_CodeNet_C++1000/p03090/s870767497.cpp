#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REP2(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,n) REP(i,0,n)
#define SORT(d) sort(d.begin(),d.end())
#define pb push_back
#define mp make_pair

int M;

vector<pair<int,int>> ans;

void dasu(int a,int b){
    ans.pb(mp(a,b));
    return;
}

void dasu2(int a,int b){
    dasu(a,b);
    dasu(a,M-b);
    dasu(M-a,b);
    dasu(M-a,M-b);
    //cout<<"arrived"<<endl;
    return;
}

int main(){
    int N; cin>>N;
    M=N; if(N%2==0) M++;
    //cout<<"M"<<M<<endl;
    int K=M/2;
    if(K>1) REP(i,1,K) dasu2(i,i+1);
    if(N%2==0 && N>4) dasu2(K,1);
    if(N%2){
        dasu(M,1);
        dasu(M,M-1);
        if(M>3)dasu(M,K);
        if(M>3)dasu(M,M-K);
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()) cout<<ans.at(i).first<<' '<<ans.at(i).second<<endl;


    
    
}