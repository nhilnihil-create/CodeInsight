// https://atcoder.jp/contests/abc009/tasks/abc009_3
// 未解決
#include <bits/stdc++.h>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second　//pairの二つ目の要素

struct Bridge{
    int a;
    int b;
    bool c=false;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<Bridge> br(m);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        br[i].a=a;
        br[i].b=b;
    }
    sort(br.begin(),br.end(),[](auto const& lhs, auto const& rhs)
    {return lhs.b < rhs.b;});
    int ans=0;
    rep(i,m){
        int x;
        if(!br[i].c){
            ans++; 
            x=br[i].b-1;
            for(int j=i;j<m;j++){
                if(br[j].c) continue;
                if(br[j].a<=x) br[j].c=true;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}