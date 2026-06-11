#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <tr1/unordered_map>
using namespace std;

#define LL long long
#define RG register int
template<typename elemType>
inline void Read(elemType &T){
    elemType X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    T=(w?-X:X);
}

int Data[200010];
tr1::unordered_map<int,int> Hash;
int N,Ans=0;

inline int GetNum(int x){
    int Res=1;
    while(Res<=x) Res<<=1;
    return Res-x;
}

int main(){
    Read(N);
    for(RG i=1;i<=N;++i){Read(Data[i]);++Hash[Data[i]];}
    sort(Data+1,Data+N+1,greater<int>());
    for(RG i=1;i<=N;++i){
        int x=GetNum(Data[i]);
        if(x==Data[i]){if(Hash[x]>=2){++Ans;Hash[x]-=2;}}
        else if(Hash[x] && Hash[Data[i]]) {++Ans;--Hash[x];--Hash[Data[i]];}
    }
    printf("%d\n",Ans);
    return 0;
}