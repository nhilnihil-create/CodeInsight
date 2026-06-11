#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
map<int,int>degree;
set <int> bpf;
set <int> pf;
int n,a[100005],num=0,minn=INF;
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<0)
            num++;
        minn=min(minn,abs(a[i]));
        ans+=abs(a[i]);
    }
    if(num%2)
        ans-=2*minn;
    printf("%lld",ans);
}
