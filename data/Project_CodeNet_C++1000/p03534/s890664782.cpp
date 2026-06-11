#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e5+10;
char in[maxn];
int cnt[5];
int main(){
    int i,j,len;
    while(~scanf("%s",in)){
        len = strlen(in);
        memset(cnt, 0, sizeof(cnt));
        for(i=0;i<len;i++){
            ++cnt[in[i] - 'a'];
        }
        int a3 = cnt[0];
        int b3 = cnt[1];
        int c3 = cnt[2];
        int cut = min(a3, min(b3,c3));
        bool flag = true;
        for(i=0;i<3;i++){
            cnt[i] -= cut;
            if(cnt[i] > 1){
                //cout<<i<<" "<<cnt[i]<<endl;
                flag = false;
                break;
            }
        }
        if(flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}