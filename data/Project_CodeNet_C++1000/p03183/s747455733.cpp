#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}


int N;
tpl blocks[1010];
ll dp[1010][10100];


ll rec(int pos, int weight){
    if(dp[pos][weight] >= 0) return dp[pos][weight];
    ll res = 0;
    if(pos == N){
        res = 0;
    }
    else{
        if(get<0>(blocks[pos]) >= weight){
            res = max(res, rec(pos + 1, min(10010, weight + get<1>(blocks[pos]))) + get<2>(blocks[pos]));
        }
        // 積まない
        res = max(res, rec(pos + 1, weight));
    }
    return dp[pos][weight] = res;
}

int main(){

    cin >> N;
    for(int i = 0; i < N; i++){
        int w, s, v;
        cin >> w >> s >> v;
        blocks[i] = tpl(s, w, v);
        
    }

    // sの小さい順番にソートしておく
    sort(blocks, blocks + N,
         [&](tpl t1, tpl t2) {
             int s1 = get<0>(t1);
             int w1 = get<1>(t1);
             int s2 = get<0>(t2);
             int w2 = get<1>(t2);
             return s1 + w1 < s2 + w2;
         });

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;

    return 0;
}
