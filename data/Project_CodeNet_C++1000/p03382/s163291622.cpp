#include<cstdio>
#include<algorithm>
int a[100005];

int abs(int u){ return u>0?u:-u; }

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    std::sort(a+1,a+1+n);
    int diff = -1, find = -1;
    for(int i = 1; i <= n-1; i++){
        int curDiff = abs(a[n]-a[i]-a[i]);
        if(diff==-1 || curDiff<diff){ 
            find = a[i];
            diff = curDiff;
        }
    }
    printf("%d %d\n",a[n],find);
    return 0;
}
