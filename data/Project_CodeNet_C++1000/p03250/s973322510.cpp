#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int abc[3];
    rep(i,3) cin>>abc[i];
    sort(abc,abc+3);
    cout<<abc[0]+abc[1]+abc[2]*10<<endl;
    return 0;
}