#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

vector<ll> to[100010];

int main(){
    ll n;cin>>n;
    rep(i,0,n-1){
        ll a,b;cin>>a>>b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ll c[100010],an=0;
    rep(i,0,n){cin>>c[i];an+=c[i];}
    sort(c,c+n);
    an-=c[n-1];
    cout<<an<<endl;
    vector<ll> num(n,-1);
    queue<ll> q;
    num[0]=c[n-1];
    q.push(0);
    ll ite=n-2;
    while(!q.empty()){
        ll now=q.front();
        q.pop();
        for(auto nx:to[now]){
            if(num[nx]!=-1)continue;
            num[nx]=c[ite];
            ite--;
            q.push(nx);
        }
    }
    rep(i,0,n){
        cout<<num[i];
        if(i!=n-1)cout<<" ";
    }
    cout<<endl;
}





