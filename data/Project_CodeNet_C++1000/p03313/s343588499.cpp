#include<cstdio>
#include<algorithm>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
using namespace std;

const int N=300010;
int n,m,a[N],r[N],mx[N];

int main(){
    scanf("%d",&m); int n=1<<m;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<n; i++)
        for (int j=i; j<n; j=(j+1)|i)
            r[j]=max(r[j],a[i]+mx[j]),mx[j]=max(mx[j],a[i]);
    for (int i=1; i<n; i++) printf("%d\n",r[i]=max(r[i],r[i-1]));
    return 0;
}