#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
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

map<int,int> Num;
int Data[200010];
int N;

bool Judge(int x){
    Num.clear();
    for(RG i=2;i<=N;++i){
        if(Data[i]<=Data[i-1]){
            while(!Num.empty()){
                int temp=Num.rbegin()->first;
                if(temp>Data[i]) Num.erase(temp); 
                else break;
            }
            int j=Data[i];
            while(Num[j]+1==x) {Num.erase(j);--j;}
            if(j==0) return false;
            ++Num[j];
        }
    }
    return true;
}

int Solve(){
    int L=2,R=N,Res=-1;
    while(L<=R){
        int mid=(L+R)>>1;
        if(Judge(mid)){Res=mid;R=mid-1;}
        else L=mid+1;
    }
    return Res;
}

int main(){
    Read(N);
    bool flag=true,flagB=true;
    for(RG i=1;i<=N;++i){
        Read(Data[i]);
        if(Data[i]!=1) flag=false;
        if(Data[i]<=Data[i-1]) flagB=false;
    }
    if(flagB){printf("1\n");return 0;}
    if(flag){printf("%d\n",N);return 0;}
    printf("%d\n",Solve());
    return 0;
}