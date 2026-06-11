#include<cstdio>
#include<algorithm>


using namespace std;

int main(){
    int n, z, w;
    scanf("%d %d %d", &n, &z, &w);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    if (n == 1) {
        int s;
        if (a[n-1] - w > 0) s = a[n-1] - w;
        else s = w - a[n-1];
        printf("%d\n", s);
    }else{
        int ans = 0;
        int s, t;
        if (a[n-1] - w > 0) s = a[n-1] - w;
        else s = w - a[n-1];
        if (a[n-1] - a[n-2] > 0) t = a[n-1] - a[n-2];
        else t = a[n-2] - a[n-1];
        ans = max(s, t);
        printf("%d\n", ans);
    }
}