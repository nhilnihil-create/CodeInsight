#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#define INF 0x3f3f3f3f
using namespace std;
inline int read(){
    int w=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        w=(w<<3)+(w<<1)+ch-48;
        ch=getchar();
    }
    return w*f;
}
int n,m,q,a[200010],b[200010],ans,vec[20010];
priority_queue<int> pq;
inline void work(){
    while(!pq.empty()){
        if(pq.size()>=m){
            vec[0]++;vec[vec[0]]=-pq.top();
        }
        pq.pop();
    }
}
signed main(){
    n=read();m=read();q=read();ans=INF;
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++){
        int now=a[i];
        for(int j=1;j<=n;j++){
            if(a[j]>=now) pq.push(-a[j]);
            else work();
        }
        work();
        if(vec[0]>=1){
            sort(vec+1,vec+vec[0]+1);
        }
        if(vec[0]>=q&&vec[1]==now){
            ans=min(ans,vec[q]-now);
        }
        memset(vec,0,sizeof(vec));
    }
    cout<<ans<<endl;
    return 0;
}