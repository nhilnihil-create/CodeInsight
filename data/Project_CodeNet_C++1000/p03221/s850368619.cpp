#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define rep11(i, n) for (int i = 1; i < (int)(n); ++i)
#define repo(i, o, n) for (int i = o; i < (int)(n); ++i)
#define repm(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1002000007
#define INF LONG_LONG_MAX

typedef pair<long long, long long> P;
//typedef pair<string, long long> Q;
//typedef tuple<string, string, long long> P;
int main(){
    long long n;
    long long m;
    cin>>n>>m;
    vector<pair<P,long long>>v(m);
    rep(i,m){
        cin>>v[i].first.first>>v[i].first.second;
    }
    rep(i,m){
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    vector<string> ans(m);
    long long j=1;
    rep(i,m){
        long long p=v[i].first.first;
        string zen = to_string(p);
        //cout<<zen.size()<<endl;
        while(6>zen.size()){
            zen="0"+zen;
        }
       
        if(i!=0){
            if(v[i-1].first.first==v[i].first.first){
            j++;
            }
            else{
                j=1;
            }
        }
        string bor= to_string(j);
        while(6>bor.size()){
            bor="0"+bor;
        }
        ans[v[i].second]=zen+bor;
    }
    rep(i,m){
        cout<<ans[i]<<endl;
    }
    
}
