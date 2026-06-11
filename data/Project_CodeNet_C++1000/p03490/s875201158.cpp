//i am too vegetable so i kuaied somebody's code in the Internet. just for this problem.
#include<cstdio>
#include<cstring>
using namespace std;
const int w=20003;
char s[10005];
int x,y,_x,len,p,sum,q,now=1;
bool ws[2][2][40009];
int main(){
    register int i;
    scanf("%s%d%d",s+1,&x,&y),len=strlen(s+1),x+=w,y+=w;
    while(now<=len&&s[now]=='F')++now,++_x;
    ws[0][0][w+_x]=1,ws[1][0][w]=1;
    while(now<=len){
        ++now,sum=0,p^=1,q^=p;
        while(now<=len&&s[now]=='F')++sum,++now;
        for(int i=w-len;i<=w+len;++i)
            ws[p][q][i]=ws[p][q^1][i+sum]|ws[p][q^1][i-sum];
    }
    if(p==1&&ws[0][q^1][x]&&ws[1][q][y]||p==0&&ws[0][q][x]&&ws[1][q][y])puts("Yes");
    else puts("No"); 
    return 0;
}