#include<cstdio>
int a[105];

int abs(int u){ return u>0?u:-u; }

int main(){
    int n;
    scanf("%d",&n);
    int sum = 0;
    for(int i = 1; i <= n; i++){ 
        scanf("%d",&a[i]);
        sum += a[i];
    }
    int diff = abs(n*a[1]-sum), find = 0;
    for(int i = 2; i <= n; i++){
        if(abs(n*a[i]-sum)<diff){
            diff = abs(n*a[i]-sum), find = i-1;
        }
    }
    printf("%d\n",find);
    return 0;
}
