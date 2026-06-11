#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

int main(void){
    int a,b;
    cin>>a>>b;
    if(a<=8 && b<=8) puts("Yay!");
    else puts(":(");
    return 0;
}