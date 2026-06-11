#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int H,W,D;
int zahyo[100000][2];
int ans[100000];
int func(int a){
    //printf("[%d]\n",a);
    if(ans[a]!=-1)return ans[a];
    if(H*W<a+D){
        ans[a]=0;
        return 0;
    }
    int ppp;
    ppp=func(a+D)+(abs(zahyo[a][0]-zahyo[a+D][0])+abs(zahyo[a][1]-zahyo[a+D][1]));
    ans[a]=ppp;
    return ppp;
}
int main(){
    for(int i=0;i<100000;i++){
        ans[i]=-1;
    }
    cin>>H>>W>>D;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int a;
            cin>>a;
            zahyo[a][0]=i;
            zahyo[a][1]=j;
        }
    }

    for(int i=1;i<=H*W;i++){
        ans[i]=func(i);
        for(int i=1;i<=H*W;i++){
            //printf("%d:[%d]\n",i,ans[i]);
        }
        //puts("\n==============");
    }

    //ans[5]=func(5);

    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        int a,b;
        cin>>a>>b;
        cout<<ans[a]-ans[b]<<endl;
    }

    for(int i=1;i<=H*W;i++){
        //printf("%d:[%d]\n",i,ans[i]);
    }

    return 0;
}
