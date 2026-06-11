#include <cstdio>
#include <cctype>
#include <algorithm>
#define MAXN 1100005
using namespace std;
int a[MAXN];
int fst[MAXN]={0};
int sec[MAXN]={0};
int tmp[25];
int temp[5];
int f[MAXN];
int read(void);
void write(int x);
int main(void){
    int len,n;
    len=read();
    n=1<<len;
    for (int i=0;i<n;i++)
        fst[i]=read();
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
        write(f[i]);
    return 0;
}

int read(void){
    int ans=0;
    char ch;
    do {
        ch=getchar();
    } while (!isdigit(ch));
    while (isdigit(ch)){
        ans=ans*10+(ch-'0');
        ch=getchar();
    }
    return ans;
}

void write(int x){
    int lg=0;
    if (!x){
        putchar('0');
        return;
    }
    while (x){
        tmp[lg++]=x%10;
        x/=10;
    }
    for (int i=lg-1;i>=0;i--)
        putchar(tmp[i]+'0');
    putchar('\n');
}