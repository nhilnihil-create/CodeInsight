///https://www.cnblogs.com/Basasuya/archive/2018/09/12/9637401.html
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct Node{
    int a, b, c;
    Node(int _a=0, int _b=0, int _c=0):a(_a), b(_b), c(_c) {}
};

vector<Node> vc;

int main()
{
    int L=read();
    int tmp=L;
    int cnt=0;
    while(tmp){
        tmp>>=1;
        cnt++;
    }
    for(int i=1;i<cnt;i++){
        vc.push_back(Node(i,i+1,0));
        vc.push_back(Node(i,i+1,(1<<i-1)));
    }
    tmp=L;
    int tmp2=0;
    bool ok=true;
    for(int i=cnt-1;i>=0;i--){
        if((tmp>>i)&1){
            tmp-=(1<<i);
            if(!ok){
                vc.push_back(Node(i+1,cnt,tmp2));
            }
            tmp2+=1<<i;ok=false;
        }
    }
    printf("%d %d\n", cnt, (int)vc.size());
    for(int i = 0; i < (int)vc.size(); ++i) {
        printf("%d %d %d\n", vc[i].a, vc[i].b, vc[i].c);
    }
    return 0;
}
