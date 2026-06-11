#include<cstdio>
int a[500005];
int maxn[500005][2];

int max(int a,int b){ return a>b?a:b; }

int min(int a,int b){ return a>b?b:a; }

void update(int&a,int&b,int c){
    if(c>a){ 
        if(b<a) b = a;
        a = c;
    }
    else if(c>b) b = c;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < (1<<n); i++) scanf("%d",&a[i]);  
    for(int i = 1; i < (1<<n); i++){
        int m0 = 0, m1 = 0;
        for(int j = i; ; j = (j-1)&i){
            update(m0,m1,a[j]);
            if(j==0) break;
        }
        maxn[i][0] = m0, maxn[i][1] = m1;
    }
    int ans = 0;
    for(int i = 1; i < (1<<n); i++){
        ans = max(ans,maxn[i][0]+maxn[i][1]);
        printf("%d\n",ans);
    }
    return 0;
}
