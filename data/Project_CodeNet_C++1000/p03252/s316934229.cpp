#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;


int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    vector<int>a(26,-1),b(26,-1);

    bool ok=true;
    rep(i,n){
        int now=s[i]-'a';
        int opo=t[i]-'a';
        if(a[now]==-1)a[now]=opo;
        else if(a[now]!=opo){
            ok=false;
            break;
        }
        if(b[opo]==-1)b[opo]=now;
        else if(b[opo]!=now){
            ok=false;
            break;
        }
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}