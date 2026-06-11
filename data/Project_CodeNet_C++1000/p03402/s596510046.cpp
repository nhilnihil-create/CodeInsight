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
    int a,b;cin>>a>>b;
    vstr grid(100);
    rep(i,50)rep(j,100){
        grid[i]+='#';
    }
    rep(i,50)rep(j,100){
        grid[i+50]+='.';
    }
    int res=0;
    for(int i=0;i<50;i+=2){
        for(int j=0;j<100;j+=2){
            if(res==a-1)break;
            grid[i][j]='.';
            res++;
        }
        if(res==a-1)break;
    }
    res=0;
    for(int i=51;i<100;i+=2){
        for(int j=0;j<100;j+=2){
            if(res==b-1)break;
            grid[i][j]='#';
            res++;
        }
        if(res==b-1)break;
    }
    cout<<100<<" "<<100<<endl;
    rep(i,100)cout<<grid[i]<<endl;
}