#include<cstdio>
int a[2005];
int b[2005];
int c[2005];

int min(int a,int b){ return a>b?b:a; }

int getCnt(int n,int k){
    if(n<k) return 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += (c[i]==1);
    return min(cnt,n-(k-1));
}

int isGood(int n,int k,int q,int l,int r){
    for(int i = 1; i <= n; i++){
        if(a[i]<l) b[i] = 0;
        else if(a[i]<=r) b[i] = 1;
        else b[i] = 2;
    }
    int p = 1, cnt = 0;
    while(p<=n){
        if(b[p]==0) p++;
        else{
            int np = p;
            while(np+1<=n && b[np+1]!=0) np++;
            int size = 0;
            for(int i = p; i <= np; i++) c[++size] = b[i];
            cnt += getCnt(size,k);
            p = np+1;
        }
    }
    if(cnt>=q) return 1;
    else return 0;
}

int main(){
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    int minn = 2e9;
    for(int i = 1; i <= n; i++){ 
        scanf("%d",&a[i]);
        minn = min(a[i],minn);
    }
    int ans = 2e9;
    for(int i = 1; i <= n; i++){
        int upper = a[i];
        int L = minn, R = a[i];
        int res = -1;
        while(L<=R){
            int M = (L+R)/2;
            if(isGood(n,k,q,M,upper)){
                res = M;
                L = M+1;
            }
            else R = M-1;
        }
        if(res!=-1) ans = min(ans,upper-res);
    }
    printf("%d\n",ans);
    return 0;
}
