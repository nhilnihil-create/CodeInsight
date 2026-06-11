#include <cstdio>
#include <algorithm>
#define MAXN 1100005
using namespace std;
int a[MAXN];
int fst[MAXN]={0};
int sec[MAXN]={0};
int temp[5];
int f[MAXN];
int main(void){
    int len,n;
    scanf("%d",&len);
    n=1<<len;
    for (int i=0;i<n;i++)
        scanf("%d",a+i);
    for (int i=0;i<n;i++)
        fst[i]=a[i];
    for (int l=0;l<len;l++){
        int tpow=1<<l;
        for (int i=1;i<n;i++){
            if (i&tpow){
                //Use i^tpow;
                int tfore=i^tpow;
                temp[0]=fst[i],temp[1]=sec[i];
                temp[2]=fst[tfore],temp[3]=sec[tfore];
                sort(temp,temp+4);
                fst[i]=temp[3],sec[i]=temp[2];
            }
        }
    }
    f[0]=fst[0];
    for (int i=1;i<n;i++)
        f[i]=max(f[i-1],fst[i]+sec[i]);
    for (int i=1;i<n;i++)
        printf("%d\n",f[i]);
    return 0;
}