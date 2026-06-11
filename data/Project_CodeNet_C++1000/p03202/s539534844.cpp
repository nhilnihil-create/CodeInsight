#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

int n, a[maxn];
int f[maxn], s[maxn], cnt;

void add(int p, int v){
    if(v == 0) return;
    f[cnt] = p;
    s[cnt++] = v;

    if(cnt >= 2 && f[cnt - 2] == f[cnt - 1]){
        s[cnt - 2] += s[cnt - 1];
        cnt--;
    }
}

bool can(int lim){
    cnt = 0;
    add(1, a[1]);
    for(int i = 2; i <= n; i++){
        if(a[i - 1] < a[i]){
            add(1, a[i] - a[i - 1]);
        }
        else if(a[i - 1] == a[i]){
            int p = f[cnt - 1];
            int v = s[cnt - 1];
            cnt--;
            if(p < lim){
                add(p, v - 1);
                add(p + 1, 1);
            }
            else{
                if(cnt == 0) return false;
                int pp = f[cnt - 1];
                int vv = s[cnt - 1];
                cnt--;
                add(pp, vv - 1);
                add(pp + 1, 1);
                add(1, v);
            }
        }
        else{
            int now = a[i - 1];
            while(true){
                if(cnt == 0) return false;
                if(now - s[cnt - 1] <= a[i]) break;
                now -= s[cnt - 1];
                cnt--;
            }
            int need = now - a[i];
            int p = f[cnt - 1];
            int v = s[cnt - 1];
            cnt--;
            add(p, v - need);

            p = f[cnt - 1];
            v = s[cnt - 1];
            cnt--;
            if(p < lim){
                add(p, v - 1);
                add(p + 1, 1);
            }
            else{
                if(cnt == 0) return false;
                int pp = f[cnt - 1];
                int vv = s[cnt - 1];
                cnt--;
                add(pp, vv - 1);
                add(pp + 1, 1);
                add(1, v);
            }
        }
    }
    return true;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int lo = 1, hi = maxn, ans = maxn;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(can(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    printf("%d", ans);
    return 0;
}