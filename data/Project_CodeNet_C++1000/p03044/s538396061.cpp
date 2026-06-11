#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;


int main(){
    ll n;
    cin>>n;
    vector<vector<P> > G(n);
    for(ll i=0;i<n-1;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--; v--;
        G[u].push_back(P(v,w));
        G[v].push_back(P(u,w));
    }
    vector<bool> ans(n,false);
    vector<bool> done(n,false);
    done[0]=true;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll now=q.front(); q.pop();
        for(P pp:G[now]){
            ll to=pp.first;
            ll w=pp.second;
            if(!done[to]){
                //cout<<now<<" "<<to<<endl;
                if(w%2==0){
                    ans[to]=ans[now];
                }else{
                    ans[to]=!ans[now];
                }
                done[to]=true;
                q.push(to);
            }
        }
    }
    for(ll i=0;i<n;i++) cout<<ans[i]<<endl;

}