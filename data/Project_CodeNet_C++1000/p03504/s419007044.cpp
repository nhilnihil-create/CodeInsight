#include<bits/stdc++.h>
using lint = int_fast64_t;

int main(){
        lint n, c;
        scanf("%ld %ld", &n, &c);

        std::vector<std::vector<lint>> scd(c, std::vector<lint>(2e5+9, 0));
        for(lint i=0; i<n; i++){
                lint s, t, cc;
                scanf("%ld %ld %ld", &s, &t, &cc);
                scd[cc-1][s*2-1] = 1;
                scd[cc-1][t*2] = -1;
        }
        for(lint i=0; i<c; i++){
                for(lint j=1; j<2e5+9; j++){
                        scd[i][j] += scd[i][j-1];
                }
        }

        lint ans = 1;
        for(lint i=0; i<2e5+9; i++){
                lint tmp = 0;
                for(lint j=0; j<c; j++) tmp += (scd[j][i]>0);
                ans = std::max(ans, tmp);
        }
        printf("%ld\n", ans);
        return 0;
}