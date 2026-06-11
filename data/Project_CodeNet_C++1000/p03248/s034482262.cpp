#include<cstdio>
#include<cstring>
int x[100005], y[100005];
char s[100005];

int main(){
    scanf("%s",s+1);
    int n = strlen(s+1);
    if(s[n]=='1' || s[1]=='0') printf("-1\n");
    else{
        int ok = 1;
        for(int i = 1; i <= n/2; i++){
            if(s[i]!=s[n-i]) ok = 0;
        }
        if(!ok) printf("-1\n");
        else{
            int size = 0;
            int p = n/2+1;
            for(int i = p+1; i <= n; i++){
                size++;
                x[size] = p, y[size] = i;
            }
            for(int i = n/2; i >= 1; i--){
                size++;
                x[size] = p, y[size] = i;
                if(s[i]=='1') p = i;
            }
            for(int i = 1; i <= size; i++){
                printf("%d %d\n",x[i],y[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
