#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,n,a[500000],id[500000][2],ans=0;
inline bool cmp(int x,int y){
    return a[x]<a[y];
}
int main(){
    scanf("%d",&N);
    n=1<<N;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    a[n]=0;
    id[0][0]=0,id[0][1]=n;
    for (int i=1;i<n;i++){
        id[i][0]=i,id[i][1]=n;
        int x[4];
        for(int j=0;j<N;j++){
            if(i&(1<<j)){
                int t=i^(1<<j);
                x[0]=id[i][0],x[1]=id[i][1],x[2]=id[t][0],x[3]=id[t][1];
                sort(x,x+4,cmp);
                id[i][0]=x[3];
                if(x[2]==x[3]) id[i][1]=x[1];
                else id[i][1]=x[2];
            }
        }
    }
    for(int i=1;i<n;i++){
        ans=max(ans,a[id[i][0]]+a[id[i][1]]);
        printf("%d\n",ans);
    }
    return 0;
}