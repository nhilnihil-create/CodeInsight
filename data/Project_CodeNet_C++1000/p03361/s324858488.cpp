#define _GLIBCXX_DEBUG
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
    int h,w;cin>>h>>w;
    vvch s(h,vch(w));
    rep(i,h)rep(j,w)cin>>s[i][j];
    vin dx={-1,0,0,1};
    vin dy={0,1,-1,0};
    bool tmp;
    int ni,nj;
    rep(i,h)rep(j,w){
        if(s[i][j]=='#'){
            tmp=false;
            rep(k,4){
                ni=i+dy[k];
                nj=j+dx[k];
                if(-1<ni&&ni<h&&-1<nj&&nj<w&&s[ni][nj]=='#')tmp=true;
            }
            if(!tmp){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}