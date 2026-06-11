#include <bits/stdc++.h>

using namespace std;

struct box {
    int w, s, v;
};
int n;
box arr[1010];
long long D[20010];

int main() {
    int i, j;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d%d%d",&arr[i].w,&arr[i].s,&arr[i].v);
    sort(arr,arr+n,[](box &a, box &b) {return a.w+a.s<b.w+b.s;});
    for (i=0;i<n;i++) {
        for (j=arr[i].w+arr[i].s;j>=arr[i].w;j--) D[j] = max(D[j],D[j-arr[i].w]+arr[i].v);
        for (j=1;j<=20001;j++) D[j] = max(D[j],D[j-1]);
    }
    printf("%lld\n",D[20001]);

    return 0;
}
