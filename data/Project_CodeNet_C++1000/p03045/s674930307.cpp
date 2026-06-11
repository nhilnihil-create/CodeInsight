#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,m;cin>>n>>m;
    int x,y,z;
    vvin p(n+1);
    rep(i,m){
        cin>>x>>y>>z;
        p[x].push_back(y);
        p[y].push_back(x);
    }
    vbo already(n+1,false);
    int ans=0;int num;
    queue<int> q;
    rep2(i,1,n+1){
        if(!already[i]){
            ans++;
            q.push(i);
            while(q.size()){
                num=q.front();q.pop();
                already[num]=true;
                for(auto tmp:p[num])if(!already[tmp])q.push(tmp);
            }
        }
    }
    cout<<ans<<endl;
}