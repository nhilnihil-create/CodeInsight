#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define LIM 100000

int ara[102], mex[LIM+5];
int n, k;

void calMex(){
    mex[0] = 0;
    for(int i = 1; i <= LIM; i++){
        set<int> grundy;
        for(int j = 1;  j <= n; j++){
            if(i < ara[j]) break;
            grundy.insert(mex[i-ara[j]]);
        }
        int mn = 0;
        auto it = grundy.begin();
        while(it != grundy.end()){
            if(*it != mn) break;
            mn++;
            it++;
        }
        mex[i] = mn;
    }
    //for(int i = 0; i < 12; i++) cout<<mex[i]<<' ';
}

int main(){
    //freopen("ip.txt", "r", stdin);
    //araonacci();
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &ara[i]);
    sort(ara, ara+n+1);
    calMex();
    if(mex[k]) printf("First\n");
    else printf("Second\n");
}

