//https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_c
//C - Different Strokes
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
struct Info{
    ll A,B;
    ll sum;
};
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<Info> abn(N);
    for(auto&& ab:abn){
        cin>>ab.A>>ab.B;
        ab.sum=ab.A+ab.B;
    }
    //a1+a3-b1
    //a1+b1+a3+b3-(b1+b2+b3)
    sort(abn.begin(),abn.end(),[](const auto&a, const auto&b){ return a.sum>b.sum;});
    ll ans=0;
    FOR(i,0,N){
        const auto& ab = abn.at(i);
        ans -= ab.B;
        if(i%2==0){
            ans += ab.sum;
        }
    }
    cout<<ans<<endl;
    return 0;
}