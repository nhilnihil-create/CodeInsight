#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int a[maxn];
int b[maxn];
int aa[maxn];
int bb[maxn];
int n;
int get_pos(int a[],int x){
    int l = -1, r = n;
    while (r - l > 1){
        int mid = (l + r) >> 1;
        if (a[mid] >=x) r = mid;
        else l = mid;
    }
    return r;
}

int get_pos2(int a[],int x){
    int l = -1, r = n;
    while (r - l > 1){
        int mid = (l + r) >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid;
    }
    return r - 1;
}
int Get(int x){
    for (int i = 0; i < n; i++){
        aa[i] = a[i] % (1 << (x + 1));
        bb[i] = b[i] % (1 << (x + 1));
    }
    sort(bb,bb + n);
    int tot = 0;
    for (int i = 0; i < n; i++){
        int lower = get_pos(bb,(1 << x)  - aa[i]);
        int upper = get_pos2(bb,(1 << (x + 1)) - aa[i]);
        if (upper - lower + 1 >= 0){
            tot += upper - lower + 1;
        }
        int pos = get_pos(bb,(1 << x) + (1 <<  (x + 1)) - aa[i]);
        tot += n - pos;
    }
    return tot;
}

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    for (int i = 0; i < n; i++){
        scanf("%d",&b[i]);
    }

    int ans = 0;
    for (int i = 0; i <= 28; i++){
        int dig = Get(i);
        ans |= (1 << i) * (dig & 1);
    }

    printf("%d\n",ans);
}
