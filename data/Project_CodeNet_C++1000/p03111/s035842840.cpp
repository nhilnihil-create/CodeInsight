#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,b)  for(int i=0;i<(int)(b);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(int i=a;i<=(int)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
typedef long long ll;
typedef long double ld;

using namespace std;
int n,A,B,C,x;
vector<int> v;

int dfs(int t,int a,int b,int c){
    if(t==n)  return min(a,min(b,c))>0 ? abs(A-a)+abs(B-b)+abs(C-c)-30 : 1e9;
    int k1=dfs(t+1,a,b,c);
    int k2=dfs(t+1,a+v[t],b,c)+10;
    int k3=dfs(t+1,a,b+v[t],c)+10;
    int k4=dfs(t+1,a,b,c+v[t])+10;
    return min(min(k1,k2),min(k3,k4));   
}
int main(){
    cs
    cin>>n>>A>>B>>C;
    rep(i,n) {cin>>x;v.push_back(x);}
    cout<<dfs(0,0,0,0);
}