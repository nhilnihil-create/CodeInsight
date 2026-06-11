#include<bits/stdc++.h>

int_fast64_t n, a[100001], l, r, mid, x, i, t1, t2;

int main(){
        scanf("%ld", &n);
        for(i=0; i<n; i++) scanf("%ld", &a[i]);

        l = 0;
        r = 1e18;
        while(r-l>1){
                mid = x = (r-l)/2+l;
                for(i=0; i<n; i++) x -= x%a[i];
                if(x<=2) l = mid;
                else r = mid;
        }
        t1 = l;

        l = -1;
        r = 1e18;
        while(r-l>1){
                mid = x = (r-l)/2+l;
                for(i=0; i<n; i++) x -= x%a[i];
                if(x<2) l = mid;
                else r = mid;
        }
        t2 = r;

        if(t1<t2) puts("-1");
        else printf("%ld %ld\n", t2, t1);

        return 0;
}
