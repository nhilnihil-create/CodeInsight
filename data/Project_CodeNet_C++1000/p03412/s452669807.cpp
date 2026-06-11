#include<cstdio>
#include<algorithm>
int a[200005];
int b[200005];

int searchLeft(int u,int n){
    int L = 1, R = n;
    int res = -1;
    while(L<=R){
        int M = (L+R)/2;
        if(b[M]>=u){
            res = M;
            R = M-1;
        }
        else L = M+1;
    }
    return res;
}

int searchRight(int u,int n){
    int L = 1, R = n;
    int res = -1;
    while(L<=R){
        int M = (L+R)/2;
        if(b[M]<=u){
            res = M;
            L = M+1;
        }
        else R = M-1;
    }
    return res;
}

//bit = highest bit
int getCnt(int n,int bit){
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]&bit){
            int lower = 0, upper = bit*2-1-a[i];
            int L = searchLeft(lower,n), R = searchRight(upper,n);
            //printf("L = %d, R = %d\n",L,R);
            if(L!=-1 && R!=-1 && L<=R) res = (res+R-L+1)%2;
            lower = bit*2+bit-a[i];
            L = searchLeft(lower,n), R = n;
            //printf("L = %d, R = %d\n",L,R);
            if(L!=-1 && R!=-1 && L<=R) res = (res+R-L+1)%2;
        }
        else{
            int lower = bit-a[i];
            int upper = bit*2-1-a[i];
            int L = searchLeft(lower,n), R = searchRight(upper,n);
            if(L!=-1 && R!=-1 && L<=R) res = (res+R-L+1)%2;
        }
        //printf("i = %d, res = %d\n",i,res);
    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for(int i = 1; i <= n; i++) scanf("%d",&b[i]);
    int ans = 0;
    for(int i = 28; i >= 0; i--){
        int mod = 1<<(i+1);
        for(int j = 1; j <= n; j++) b[j] %= mod, a[j] %= mod;
        std::sort(b+1,b+1+n);
        int res = getCnt(n,mod/2);
        if(res!=0){
            //printf("i = %d\n",i);
            //for(int j = 1; j <= n; j++) printf("%d ",a[j]);
            //printf("\n");
            //for(int j = 1; j <= n; j++) printf("%d ",b[j]);
            //printf("\n");
            ans += mod/2;
        }
    }
    printf("%d\n",ans);
    return 0;
}
