#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int ans=-INT_MAX;
int n,a[10];
vector<vector<int>>f,p;

void calc(void){
    bool ok=false;
    rep(i,n)if(a[i]==1)ok=true;
    if(!ok)return;
    int sum=0;
    rep(i,n){
        int cnt=0;
        rep(j,10){
            if(a[j]&f[i][j])cnt++;
        }
        sum+=p[i][cnt];
    }
    ans=max(ans,sum);
    return;
}

void dfs(int x){
    if(x==10){
        calc();
        return;
    }
    a[x]=0,dfs(x+1);
    a[x]=1,dfs(x+1);
}

int main(){
    cin>>n;
    f=vector<vector<int>>(n,vector<int>(10));
    p=vector<vector<int>>(n,vector<int>(11));
    rep(i,n){
        rep(j,10){
            cin>>f[i][j];
        }
    }
    rep(i,n)rep(j,11){
        cin>>p[i][j];
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}