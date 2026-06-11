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

vector<int> d(100,0);

void primefact(int N){
    vector<pair<int,int>> ans(0);
    int a=2;
    while(N>=a*a){
        if(N%a==0){
            ans.push_back({a,0});
            int A=ans.size()-1;
            while(N%a==0){
                ans.at(A).second++;
                N/=a;
            }
        }
        a++;
    }
    if(N>1)ans.push_back({N,1});
    rep(i,sz(ans)){
        d.at(ans.at(i).first)+=ans.at(i).second;
    }
    return;
}

int main() {
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)primefact(i);
    vector<int> D(0);
    rep(i,100){
        if(d.at(i))D.pb(d.at(i));
    }
    vector<vector<int>> dp(sz(D)+1,vector<int>(76));
    vector<int> list={1,3,5,15,25,75};
    dp.at(0).at(1)=1;
    rep(j,sz(D)){
        int x=D.at(j);
        for(int i=0;i<6;i++){
            if(x<list.at(i)-1)break;
            rep(k,6){
                if(list.at(k)*list.at(i)<76)dp.at(j+1).at(list.at(k)*list.at(i))+=dp.at(j).at(list.at(k));
            }
        }
    }
    cout<<dp.at(sz(D)).at(75)<<endl;
}