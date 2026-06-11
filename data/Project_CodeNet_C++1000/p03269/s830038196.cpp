#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 5000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

struct edge { int from, to, cost; };

signed main(){
    int L; cin>>L;
    vector<edge> ans;
    for(int i=19; i>=1; i--){
        if(L==1){
            edge e; e.from=i; e.to=i+1; e.cost=0;
            ans.push_back(e);
        }else{
            if(L%2==1){
                edge e; e.from=1; e.to=i+1; e.cost=L-1;
                ans.push_back(e);
            }
            edge e,f;
            e.from=i; e.to=i+1; e.cost=0;
            L/=2;
            f.from=i; f.to=i+1; f.cost=L;
            ans.push_back(e);
            ans.push_back(f);
        }
    }
    cout<<20<<' '<<ans.size()<<endl;
    rep(i,ans.size()){
        cout<<ans.at(i).from<<' '<<ans.at(i).to<<' '<<ans.at(i).cost<<endl;
    }
}