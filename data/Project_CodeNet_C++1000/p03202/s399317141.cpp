#include<cstdio>
const int N=2e5+6;
int n,A[N];
int a[N],b[N],top;
bool check(int c){
    top=0;
    for(int i=2;i<=n;++i)
    if(A[i]<=A[i-1]){
        int pos=A[i];
        while(top&&a[top]>pos)--top;
        if(!top||a[top]!=pos)a[++top]=pos,b[top]=1;else{
            while(top&&a[top]==pos&&b[top]==c-1)--top,--pos;
            if(!pos)return 0;
            if(top&&a[top]==pos)++b[top];else a[++top]=pos,b[top]=1;
        }
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",A+i);
    bool ok=1;
    for(int i=1;i<=n;++i)if(A[i]<=A[i-1])ok=0;
    if(ok){puts("1");return 0;}
    int l=2,r=1e9,ans=1e9;
    while(l<=r){
        const int mid=l+r>>1;
        if(check(mid))r=(ans=mid)-1;else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}