#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
    char ch;
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
    if (ch=='-'){
        int s=0;
        while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
        return -s;
    }
    int s=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
    return s;
}

const int N = 1e5+5;

int n;
int a[N];
int pre[N];
int tree[N*2];

void add(int x){
    x+=n+1;
    for(;x<=n*2+2;x+=x&-x)tree[x]++;
}

int query(int x){
    int ret=0;
    x+=n+1;
    for(;x;x-=x&-x)ret+=tree[x];
    return ret;
}

bool check(int lim){
    fo(i,1,n){
        pre[i]=pre[i-1];
        if (a[i]<=lim)pre[i]++;
        else pre[i]--;
    }
    fo(i,0,n*2+2)tree[i]=0;
    add(0);
    LL tot=0;
    fo(i,1,n){
        tot+=query(pre[i]-1);
        add(pre[i]);
    }
    LL all=1ll*n*(n+1)/2;
    return (2*tot > all);
}

int main(){
    n=get();
    fo(i,1,n)a[i]=get();
    int l=1,r=1e9,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if (check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
/*
in this case (<= element) > (> element) (no equality) again depends as per definition of medium
also in this case tot > all/2     strict (   " "    )       (Observation)
also we have to go right to search
e.g.  1 2 3 5 5  /// 2 -> 3..........       (Observe)
*/