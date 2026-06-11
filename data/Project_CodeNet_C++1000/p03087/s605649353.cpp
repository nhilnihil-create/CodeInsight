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
    int N,Q;
    cin>>N>>Q;
    string S;
    cin>>S;
    vector<int> AC(N);
    int now=0;
    rep(i,N-1){
        if(S.at(i)=='A' && S.at(i+1)=='C'){
            now++;
        }
        AC.at(i+1)=now;
    }
    rep(query,Q){
        int l,r;
        cin>>l>>r;
        --l;--r;
        cout<<AC.at(r)-AC.at(l)<<endl;
    }
}