#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int y;
    bool flag = false;
    cin >> n >> y;

    for(int i=0;i<=n;i++){
        for(int j=0; j<=n-i;j++){
            for(int k=0;k<=n-i-j;k++){
                if(10000*i+5000*j+1000*k == y && i+j+k==n){
                    printf("%d %d %d\n", i, j ,k);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(!flag)
        printf("-1 -1 -1\n");
}