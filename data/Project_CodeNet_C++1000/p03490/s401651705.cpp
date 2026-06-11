#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 1000010
#define MAX_V 900010
#define vec vector<int>
using namespace std;

bool check(vec v,int x){
    bitset<40000> b;
    b[20000]=1;
    rep(i,v.size()){
        int t=v[i];
        b=(b<<t)|(b>>t);
    }
    return b[20000+x];
}
main(){
    string s;
    int x,y;
    cin>>s>>x>>y;
    vector<int> v1,v2;
    int count=0,pos=0;
    while(s[pos]=='F'&&pos<s.size()){
        x--;pos++;
    }
    count++;
    pos++;
    while(pos<s.size()){
        int t=0;
        while(s[pos]=='F'){
            t++;pos++;
        }
        if(count%2){
            v2.pb(t);
        }
        else v1.pb(t);
        count++;pos++;
    }
    cout<<(check(v1,x)&&check(v2,y)?"Yes":"No");
}