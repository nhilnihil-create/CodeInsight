#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
ll mod=1e9+7;
bool dx[2][18000],dy[2][18000];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string ss;cin>>ss;
    int a,b;cin>>a>>b;
    vector<int> d;
    int p=0;
    rep(i,ss.size()){
        if(ss[i]=='T'){
            d.push_back(i-p);
            p=i+1;
        }
        if(i==ss.size()-1&&ss[i]!='T')d.push_back(ss.size()-p);
    }
    int g=8000;
    rep(i,2)rep(j,18000)dx[i][j]=dy[i][j]=0;
    dx[0][g]=1;
    dy[0][g]=1;
    for(int i=0;i<d.size();i+=2)rep(j,18000){
        int k=i/2;
        if(dx[k&1][j]){
            if(j+d[i]<18000)dx[(k+1)&1][j+d[i]]=1;
            if(i>0)if(j-d[i]>0)dx[(k+1)&1][j-d[i]]=1;
            dx[k&1][j]=0;
        }
    }
    for(int i=1;i<d.size();i+=2)rep(j,18000){
        int k=i/2;
        if(dy[k&1][j]){
            if(j+d[i]<18000)dy[(k+1)&1][j+d[i]]=1;
            if(j-d[i]>0)dy[(k+1)&1][j-d[i]]=1;
            dy[k&1][j]=0;
        }
    }
    if((dx[0][a+g]||dx[1][a+g])&&(dy[0][b+g]==1||dy[1][b+g]==1))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
