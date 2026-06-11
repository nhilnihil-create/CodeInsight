#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    int x;
    scanf("%d",&x);
    int ans=0;
    for(int b=1;b<=1000;++b){
        for(int p=2;p<=10;++p){//2^10>1000
            int temp=pow(b,p);
            if(temp<=x)
                ans=max(ans,temp);
        }
    }
    printf("%d\n",ans);
    return 0;
}