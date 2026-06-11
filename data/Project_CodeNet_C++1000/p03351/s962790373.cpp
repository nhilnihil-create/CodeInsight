#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    bool ans=true;
    if(abs(c-a)>d) if(abs(b-a)>d || abs(c-b)>d) ans=false;
    if(ans) puts("Yes");
    else puts("No");
    return 0;
}