#include<bits/stdc++.h>

int main(){
        int n;
        scanf("%d", &n);
        char fie[n][n];
        for(int i=0; i<n; i++) scanf("%s", fie[i]);

        int ans = 0;
        for(int i=0; i<n; i++){
                int cnt = 0;
                for(int j=0; j<n; j++){
                        for(int k=j; k<n; k++){
                                if(fie[j][(i+k)%n]!=fie[k][(i+j)%n]) break;
                                cnt++;
                        }
                }
                if(cnt==n*(n+1)/2) ans++;
        }
        printf("%d\n", ans*n);
        return 0;
}