#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,A,B,C,ans=1e7,l[10];
void dfs(int i,int a,int b,int c,int m){
    if(i==n)if(a==A||b==B||c==C)return;
    else{
        ans=min(ans,abs(a)+abs(b)+abs(c)+m);
        return;
	}
    dfs(i+1,a-l[i],b,c,m+(a==A?0:10));
    dfs(i+1,a,b-l[i],c,m+(b==B?0:10));
    dfs(i+1,a,b,c-l[i],m+(c==C?0:10));
    dfs(i+1,a,b,c,m);
}
int main(){
    cin>>n>>A>>B>>C;
    for(int i=0;i<n;i++)cin>>l[i];
    dfs(0,A,B,C,0);
    cout<<ans<<endl;
    return 0;
}