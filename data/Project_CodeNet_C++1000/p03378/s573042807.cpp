#include<bits/stdc++.h>
#define REP(i,b,e) for(int i=b; i<e; i++)

int main(){
        int n, m, x;
        scanf("%d %d %d", &n, &m, &x);
        int s = 0, g = 0;
        REP(i, 0, m){
            int a;
            scanf("%d", &a);
            if(a>x) g++;
            else s++;
        }
        printf("%d\n", std::min(s, g));
        return 0;
}