#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;


vector<vector<pll>> edge; //to,rev
vector<vector<ll>> node;
vector<bool> color;
vector<bool> used;

stack<ll> S;

string solve(){
    for(int i=0;i<edge.size();i++){
        vector<ll> a(2,0);
        for(int t=0;t<edge[i].size();t++){
            ll to=edge[i][t].F;
            a[color[to]]++;
        }
        if(a[0]==0 || a[1]==0){S.push(i);}
        node[i]=a;
    }
    while(!S.empty()){
        ll w=S.top();
        S.pop();
        if(used[w]){continue;}
        used[w]=true;
        for(int i=0;i<edge[w].size();i++){
            ll to=edge[w][i].F;
            node[to][color[w]]--;
            if(node[to][color[w]]==0){S.push(to);}
        }
    }
    ll a[2]={};
    for(int i=0;i<used.size();i++){
        if(!used[i]){a[color[i]]++;}
    }
    if(a[0] && a[1]){return "Yes";}
    return "No";
}





int main(){
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    edge.resize(n);
    node.resize(n);
    color.resize(n);
    for(int i=0;i<n;i++){color[i]=s[i]=='A';}
    used.resize(n,false);
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        u--; v--;
        edge[u].push_back({v,-1});
        edge[v].push_back({u,-1});
    }
    cout<<solve()<<endl;
    
    
    
    return 0;
}
