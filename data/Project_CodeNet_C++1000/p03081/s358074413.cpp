#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define INF 9000000000000000000
#define R(i) V[i]-V[i-1]
int n,q;
string s;
char V[200010][2];
bool judgeL(int x){
    rep(i,q){
        if(V[i][0]==s[x]){
            if(V[i][1]=='L')x--;
            else x++;
        }
        if(x==-1)return true;
        
    }
    return false;
}
bool judgeR(int x){
    rep(i,q){
        if(V[i][0]==s[x]){
            if(V[i][1]=='L')x--;
            else x++;
        }
        if(x==n)return true;
    }
    return false;
    
}
signed main() {
    cin>>n>>q>>s;
    rep(i,q)cin>>V[i][0]>>V[i][1];
    //二分探索
    int ans=0;
    int f=0,e=n;
    while(e>f){
        int x=(f+e)/2;
        if(judgeL(x))f=x+1;
        else e=x;
    }
    //cout<<f<<endl;
    ans+=f;
    f=0;e=n;
    while(e>f){
        int x=(f+e)/2;
        if(judgeR(x))e=x;
        else f=x+1;
    }
    //cout<<e<<endl;
    ans+=(n-e);
    cout<<n-ans<<endl;;
    
}