#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const int maxn = 20005;
pair<int, pair<int, int> > p[maxn];
// s, w, v

int n;


typedef long long LL;

LL dp[maxn];
LL c[maxn];

void add(int pos, LL val){
    for(int i = pos;i < maxn;i += i & -i){
        c[i] = max(c[i], val);
    }
} 

LL sum(int pos){
    LL res = 0;
    for(int i = pos;i > 0;i -= i & -i){
        res = max(res, c[i]);
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d", &p[i].second.first, &p[i].first, &p[i].second.second);
        p[i].first += p[i].second.first;
    }
    sort(p + 1, p + 1 + n);
    for(int i = 1;i <= n;i++){
        //cout << i << endl;
        for(int j = 1;j < maxn;j++){
            add(j, dp[j]);
        }
        int w = p[i].second.first;
        int s = p[i].first - w;
        int v = p[i].second.second;
        //cout << w << " " << s << " " << v << endl;
        dp[w] = max(dp[w], 1LL * v);
        //cout << i << endl;
        for(int j = w;j < maxn;j++){
            //int rb = max(0, min(s, j - w));
            int rb = min(s, j - w);
            dp[j] = max(dp[j], sum(rb) + v);
        }
        //for(int j = 0;j <= 5;j++){
        //    cout << j << " " << dp[j] << endl;
        //}
    }
    cout << dp[maxn - 1] << endl;
    return 0;
}
