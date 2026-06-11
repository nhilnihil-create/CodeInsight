#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int n,q;
char t[200001],d[200001];
string s;
int solve(int x,int y){
    rep(i,q){
        if(x==-1||x==n) break;
        if(s[x]==t[i]){
            if(d[i]=='L') x--;
            else x++;
        }
    }
    if(y==0&&x==-1) return 1;
    if(y==1&&x==n) return 1;
    return 0;
}
int ok,ng,mid;
int search(int x){
  while(abs(ok-ng)>1){
    int mid=(ok+ng)/2;
    if(solve(mid,x)) ok=mid;
    else ng=mid;
  }
}
int main(){
    cin>>n>>q>>s;
    rep(i,q) cin>>t[i]>>d[i];
    ok=-1,ng=n,search(0);
    int left=ok;
    ok=n,ng=-1,search(1);
    int right=ok;
    cout<<right-left-1;
}