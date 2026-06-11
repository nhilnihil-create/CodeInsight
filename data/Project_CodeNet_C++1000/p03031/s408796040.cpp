
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
#define PI 3.14159265359
#define dij priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
typedef long long ll;
//
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(m);
    rep(i,m){
        int k;cin>>k;
        rep(j,k){
            int s;cin>>s;
            v[i].push_back(s);
        }
    }
    vector<int> che;
    rep(i,m){
        int p;cin>>p;
        che.push_back(p);
    }
    int ans=0;

    rep(i,1<<n){
        bool flag=false;
        int co=0;
        vector<int> vv;
        rep(j,n){
            int mask=1;
            if(i&mask<<j)vv.push_back(j);
        }
//        for(auto e:vv)cout<<e;cout<<endl;
        rep(j,m){
            int co2=0;
            for(auto e:vv){
                if(find(all(v[j]),e+1)!=v[j].end())co2++;
            }
//            cout<<co2<<endl;
            if(co2%2==che[j])co++;
        }
//        cout<<co<<endl;
        if(co==m)ans++;
    }
    cout<<ans<<endl;
}
