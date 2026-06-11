#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<bitset>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return f*ans;
}
const int MAXN=3e5+11;
char str[MAXN];int N,S[MAXN];
int Q(int l,int r){if(l>r) return 0;return S[r]-S[l-1];}
int main(){
    N=read();scanf("%s",str+1);
    for(int i=1;i<=N;i++) S[i]=S[i-1]+(str[i]=='W');
    int Minn=N;
    for(int i=1;i<=N;i++){
        Minn=min(Minn,Q(1,i-1)+(N-i)-Q(i+1,N));
    }printf("%d\n",Minn);return 0;
}

