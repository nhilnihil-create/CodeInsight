#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int n;
vector<int> d(50);
int dfs(int i,vector<int>& x){
    if(i==n){
        int buf=24;
        x.push_back(0);
        x.push_back(24);
        sort(x.begin(),x.end());
        rep(j,n+1){
            chmin(buf,x[j+1]-x[j]);
        }
        return buf;
    }
    
    int res=0;
    auto nx1=x;
    nx1.push_back(d[i]);
    int buf=dfs(i+1,nx1);chmax(res,buf);
    auto nx2=x;
    nx2.push_back(24-d[i]);
    buf=dfs(i+1,nx2);chmax(res,buf);
    return res;
    
}

int main(void){
    cin>>n;
    map<int,int> mp;
    rep(i,n){
        cin>>d[i];
        mp[d[i]]++;
    }
    
    for(auto& p:mp){
        if(p.second>=3||p.first==0){
            cout<<0<<endl;
            return 0;
        }
        
    }
    if(n>=13){
        cout<<1<<endl;
        return 0;
    }
    vector<int> x;
    int res=dfs(0,x);
    cout<<res<<endl;
}