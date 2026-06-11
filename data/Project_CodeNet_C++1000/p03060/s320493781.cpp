#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    vector<int> V(N);
    rep(i,N){
        cin>>V.at(i);
    }
    rep(i,N){
        int c;
        cin>>c;
        V.at(i)-=c;
    }
    int nas=0;
    rep(i,N){
        if(V.at(i)>0){
            nas+=V.at(i);
        }
    }
    cout<<nas<<endl;
}