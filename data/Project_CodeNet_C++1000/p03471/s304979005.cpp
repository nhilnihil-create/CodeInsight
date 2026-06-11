#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n,s;cin>>n>>s;
    if(s % 1000 != 0) {
        printf("-1 -1 -1\n");
    } else {
        s /= 1000;
        bool flg = false;
        for(int i = 0;i <= 20000;i++) {
            for(int j = 0;j <= 10000;j++) {
                if(i + j*5 > s) {
                    continue;
                }
                if( ((s - (i + j*5)) % 10 == 0 ) ) {
                    if(i + j + ((s - (i + j*5))/10) == n) {
                        printf("%d %d %d\n",((s - (i + j*5))/10),j,i);
                        return 0;
                    }
                }
            }
        }
        printf("-1 -1 -1\n");
    }

    return 0;
}