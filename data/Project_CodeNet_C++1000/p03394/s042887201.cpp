#include<bits/stdc++.h>
using namespace std;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n;
int main() {
    n=gi();
    if(n==3) return puts("2 5 63"),0;
    if(n==4) return puts("2 5 20 63"),0;
    if(n==6) return puts("2 3 4 5 6 10"),0;
    for(int x=1;x<=5000;x++)
        for(int y=1;y<=2500;y++) {
            int z=n-2*x-2*y;
            if(0<=z&&z<=5000) {
                x*=2,y*=2;
                int cnt=0;
                for(int i=1;i<=30000;i++)
                    if(i%2==0&&i%3!=0) {
                        printf("%d ",i),++cnt;
                        if(cnt==x) break;
                    }
                cnt=0;
                for(int i=1;i<=30000;i++)
                    if(i%2!=0&&i%3==0) {
                        printf("%d ",i),++cnt;
                        if(cnt==y) break;
                    }
                for(int i=6;i<=6*z;i+=6) printf("%d ",i);
                return 0;
            }
        }
    return 0;
}
