#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 200003;
int n, a[N], stk[N], num[N], top;
inline bool check(int m){
    top = 1; stk[1] = 1; num[1] = a[1];
    for(Rint i = 2;i <= n;++ i){
        if(a[i] > a[i - 1]){
            if(stk[top] == 1) num[top] += a[i] - a[i - 1];
            else stk[++ top] = 1, num[top] = a[i] - a[i - 1];
        } else {
            int x = a[i - 1] - a[i];
            while(top && x >= num[top]) x -= num[top], -- top;
            num[top] -= x;
            int t = 0;
            while(stk[top] == m) t += num[top], -- top;
            if(!top) return false;
            if(num[top] == 1) ++ stk[top];
            else {
                -- num[top], stk[top + 1] = stk[top] + 1, ++ top, num[top] = 1;
            }
            if(t) stk[++ top] = 1, num[top] = t;
        }
    }
    return true;
}
int main(){
    scanf("%d", &n);
    for(Rint i = 1;i <= n;++ i) scanf("%d", a + i);
    int l = 1, r = n, ans, mid;
    while(l <= r){
        mid = l + r >> 1;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", ans);
}