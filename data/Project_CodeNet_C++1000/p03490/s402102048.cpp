#include <bits/stdc++.h>
#define ll long long
#define llu unsigned long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAX = 1e5 + 10;
const int mod = 1e9;
int N, M, Q, K;
vector<int> vec[2];
int dp[16100][4010], dest[2];
bool dflag[2];

int rec(int pos, int vi, int init, int dir){
    if(vi >= vec[dir].size()){
        if(pos == dest[dir]) dflag[dir] = true;
        return 1;
    }
    int &ret = dp[pos][vi];
    if(ret != -1) return 1;
    ret = 1;

    rec(pos + vec[dir][vi], vi + 1, 0, dir);
    if(dflag[dir]) return 1;
    if(!init) rec(pos - vec[dir][vi], vi + 1, 0, dir);
    return 1;
}

int main()
{
    int i, j, k;
    string s;
    cin >> s >> dest[0] >> dest[1];

    int pos = 0;
    int dir = 0;
    int n= s.size();

    while(pos < n){
        int cnt = 0;
        while(pos < n && s[pos] == 'F') {cnt++; pos++;}
        vec[dir].push_back(cnt);
        pos++;
        dir = !dir;
    }

    dest[0] += 8000; dest[1]+= 8000;
    memset(dp, -1, sizeof(dp));
    rec(8000, 0, 1, 0);
    if(!dflag[0]){
        printf("No\n");
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    rec(8000, 0, 0, 1);
    if(!dflag[1]){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
}
