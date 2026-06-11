#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<bitset>
#define int long long
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
const int MAXN=2e5+11;
int N,S1[MAXN],S2[MAXN],ans;
signed main(){
    N=read();for(int i=1;i<=N;i++){int x=read();S1[i]=S1[i-1]^x,S2[i]=S2[i-1]+x;}
    for(int i=1;i<=N;i++){
        int l=1,r=i,res;
        while(l<=r){
            int mid=(l+r)>>1;
            if((S1[i]^S1[mid-1])==(S2[i]-S2[mid-1])) res=mid,r=mid-1;
            else l=mid+1;
        }ans+=(i-res+1);
    }printf("%lld\n",ans);return 0;
}
