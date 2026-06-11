#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    string s;
    cin>>s;
    int r=0,b=0;
    rep(i,N){
        if(s.at(i)=='R')r++;
        else b++;
    }
    if(r>b)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}