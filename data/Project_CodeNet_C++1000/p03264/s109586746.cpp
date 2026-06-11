#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    int k;
    scanf("%d",&k);
    int ans=(k/2)*((k+1)/2);
    printf("%d\n",ans);
    return 0;
}