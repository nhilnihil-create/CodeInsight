#include<cstdio>
long long x[1005], y[1005];
long long r[1005], c[1005];
long long power[105];
long long dx[4] = {0,0,1,-1};
long long dy[4] = {1,-1,0,0};
char direct[4] = {'D','U','L','R'};
char s[50];

long long abs(long long u){ return u>0?u:-u; }

int isReach(long long x,long long y,int i){
    if(i==-1) return x==0 && y==0;
    long long sum = abs(x)+abs(y);
    if(sum<=power[i+1]-1) return 1;
    else return 0;
}

int main(){
    power[0] = 1;
    for(int i = 1; i <= 40; i++) power[i] = power[i-1]*2;
    int n;
    scanf("%d",&n);
    int bit = -1, ok = 1;
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld",&x[i],&y[i]);
        r[i] = x[i], c[i] = y[i];
        int cur = (abs(x[i])+abs(y[i]))%2;
        if(i==1) bit = cur;
        else{
            if(bit!=cur) ok = 0;
        }
    }
    if(!ok) printf("-1\n");
    else{
        int m = -1;
        if(bit%2) m = 31;
        else m = 32;
        printf("%d\n",m);
        for(int i = 1; i <= 31; i++) printf("%lld ",power[i-1]);
        if(bit%2==0) printf("1 ");
        printf("\n");
        //test
        //printf("%d\n",n);
        for(int i = 1; i <= n; i++){
            int size = 0;
            if(bit%2==0){
                for(int j = 0; j < 4; j++){
                    long long xx = x[i]+dx[j], yy = y[i]+dy[j];
                    if(isReach(xx,yy,30)){
                        s[++size] = direct[j];
                        x[i] = xx, y[i] = yy;
                        break;
                    }
                }
            }
            for(int t = 30; t >= 0; t--){
                for(int j = 0; j < 4; j++){
                    long long xx = x[i]+dx[j]*power[t], yy = y[i]+dy[j]*power[t];
                    if(isReach(xx,yy,t-1)){
                        s[++size] = direct[j];
                        x[i] = xx, y[i] = yy;
                        break;
                    }
                }
            }
            //printf("x = %lld,y = %lld\n",x[i],y[i]);
            for(int j = size; j >= 1; j--) printf("%c",s[j]);
            printf("\n");
        }
        //for(int i = 1; i <= n; i++) printf("%lld %lld\n",r[i],c[i]);
        //printf("\n");
    }
    return 0;
}

