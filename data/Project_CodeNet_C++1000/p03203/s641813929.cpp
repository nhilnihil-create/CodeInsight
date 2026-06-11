#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

#define RG register int

template<typename elemType>
inline void Read(elemType &T){
    elemType X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    T=(w?-X:X);
}

int Pos[200010];
int H,W,N;

int main(){
    Read(H);Read(W);Read(N);
    for(RG i=1;i<=H;++i) Pos[i]=i+1;
    for(RG i=1;i<=N;++i){
        int x,y;Read(x);Read(y);
        Pos[x]=min(Pos[x],y);
    }
    int R=1;
    for(RG i=1;i<=H;++i){
        if(i==H || R>=Pos[i+1]){printf("%d\n",i);break;}
        if(Pos[i+1]!=R+1) ++R;
    }
    return 0;
}