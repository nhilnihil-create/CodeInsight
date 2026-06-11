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
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,h;cin>>n>>h;
    priority_queue<pair<int,int>> q;
    int a,b;
    rep(i,n){
        cin>>a>>b;
        q.push(mp(a,0));
        q.push(mp(b,1));
    }
    int res=0;
    while(h>0){
        auto p=q.top();q.pop();
        if(p.second==1){
            h-=p.first;
            res++;
        }
        else{
            int tmp=p.first;
            res+=(h+tmp-1)/tmp;
            break;
        }
    }
    cout<<res<<endl;
}