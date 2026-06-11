#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


ll b[200010],w[200010];


int main(){
    ll N;cin>>N;
    string s;cin>>s;
    rep(i,1,N){
        if(s.at(i-1)=='#')b[i]++;
        b[i]+=b[i-1];
    }
    for(int i=N-2;i>=0;i--){
        if(s.at(i+1)=='.')w[i]++;
        w[i]+=w[i+1];
    }
    ll MIN=99999999999999;
    rep(i,0,N){
        MIN=min(MIN,b[i]+w[i]);
    }
    cout<<MIN<<endl;
}





