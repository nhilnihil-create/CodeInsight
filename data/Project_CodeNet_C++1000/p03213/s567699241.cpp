#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
 
using namespace std;
bool vis[200];
int que[100],sum[100];
int tot;
void get(){
    tot=0;
    for(int i=2;i<=100;i++){
        int tmp=i*i;
        if(!vis[i]){
            que[++tot]=i;
            //cout<<i<<endl;
        if(tmp>100) continue;
            while(tmp<=100){
                vis[tmp]=true;
                tmp+=i;
            }
        }
    }
}
int main(){
    int n;
    get();
    scanf("%d",&n);
    int res=0,ans=0;
    for(int i=1;i<=tot;i++){
        int pp=0;
        for(int j=que[i];j<=n;j+=que[i]){
            int tmp=j;
            while(!(tmp%que[i])){
                pp++;
                tmp/=que[i];
            }
        }
        //cout<<pp<<' '<<i<<endl;
        sum[i]=pp;
        /*if(que[i]>=5){
            if(que[i]*4<=n) ans++,res++;
            else if(que[i]*2<=n) ans++;
        }
        else if(que[i]<5){
            if(que[i]*que[i]<=n) ans++,res++;
            else if(que[i]*2<=n) ans++;
        }*/
    }
    int a=0,b=0,c=0,d=0,p=0;
    //cout<<res<<' '<<ans<<endl;
    for(int i=1;i<=tot;i++){
        if(sum[i]>=74) p++;
        if(sum[i]>=24) a++;
        if(sum[i]>=14) b++;
        if(sum[i]>=4) c++;
        if(sum[i]>=2) d++;
    }
    //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    int ANS=a*(d-1);
    ANS+=b*(c-1);
    ANS+=((c-1)*c/2)*(d-2);
    ANS+=p;
    printf("%d\n",ANS);
    return 0;
}