#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>


#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using lli = long long int;


std::map<int, int> Map;


int main(void){
    // 入力
    int n; scanf("%d", &n);
    REP(i, n) {
        int k;
        scanf("%d", &k);
        Map[k]++;
    }

    // 実装
    int ans = 0;
    // 逆順
    for(auto itr = Map.rbegin(); itr != Map.rend(); ++itr){
        int a, b; std::tie(a, b) = *itr;
        int t = 1;
        while(t <= a) t *= 2;
        if(Map.find(t - a) != Map.end()){
            // 自身を参照する場合
            if(t == 2 * a){
                Map[a] = b % 2;
                ans += b / 2;
                continue;
            }
            int bb = Map[t-a];
            // 小さい方
            int mn = (bb > b) ? b : bb;
            Map[a] -= mn;
            Map[t-a] -= mn;
            ans += mn;
        }
    }
    // 出力
    printf("%d\n", ans);

    return 0;
}