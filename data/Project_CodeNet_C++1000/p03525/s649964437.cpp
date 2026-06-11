#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

// Use of dynamic bitset to convert decimal numbers.
// https://stackoverflow.com/questions/42759330/use-of-dynamic-bitset-to-convert-decimal-numbers
// 10進数 → 2進数.
// @param n: 2進数へ変換したい10進数.
// @param d: 2進数表記する桁数.
// @return: 2進数.
string decimalToBinary(int n, int d) {
    string ret;
    int ln = abs(n);
    while(ln){
        ret = string((ln & 1) ? "1" : "0") + ret;
        ln /= 2;
    }
    while(ret.size() < d) ret = "0" + ret;
    if(n < 0) ret = "-" + ret;
    return ret;
}

int D[25];

int main(){
    
    // 1. 入力情報.
    int N, d;
    scanf("%d", &N);
    map<int, int> m;
    rep(i, N){
        scanf("%d", &d);
        D[d]++;
    }
    
    // 2. N が 24以上ならば, 0 の はず.
    if(N >= 24){
        printf("%d\n", 0);
        return 0;
    }
    
    // 3. もし, 3個以上選択していたら, 0 を 出力して終了.
    rep(i, 25){
        if(D[i] > 2){
            printf("%d\n", 0);
            return 0;
        }
    }
    
    // 4. 時刻をカウント.
    // ex.
    // 3
    // 7 12 8
    // -> 7 8 12 16 17 を 保存.
    set<int> s;
    rep(i, 25) if(D[i] > 0) s.insert(i), s.insert(24 - i);
    // for(auto &p : s) printf("%d ", p);
    // printf("\n");
    
    // 5. 考えられる時刻の差を書き出したときの最小値を, 
    // それぞれ計算し, その中で, 最大となるものを取得.
    //  0,  1, ... , 12 の 13桁分は, bit = 1 で 探索対象.
    // 13, 14, ... , 24 の 12桁分は, bit = 0 で 探索対象.
    // ex.
    // c[7] = '1' だったら,  7 が 比較対象の時刻.
    // c[7] = '0' だったら, 17 が 比較対象の時刻.
    string c;
    int ans = 0;
    rep(i, 1 << 13){
        c = decimalToBinary(i, 13);
        // printf("%s\n", c.c_str());
        
        // チェック対象かを確認.
        vector<int> v;
        v.push_back(0);
        rep(j, 13){
            if(D[j] == 2 && s.count(j) > 0){
                v.push_back(j);
                v.push_back(24 - j);
                continue;
            }
            if(s.count(j) > 0      && c[j] == '1') v.push_back(j);
            if(s.count(24 - j) > 0 && c[j] == '0') v.push_back(24 - j);
        }
        
        // 人数チェック(※なくても良さそうに見える).
        if(v.size() != N + 1) continue;
        
        // (N + 1)人 の 差分を確認.
        int diff = 123454321;
        int t = 0;
        rep(j, N + 1){
            rep(k, N + 1){
                t = abs(v[j] - v[k]);
                if(j != k) diff = min(diff, min(t, 24 - t));
            }
        }
        
        // 更新.
        ans = max(ans, diff);
    }
    
    // 6. 出力.
    printf("%d\n", ans);
    return 0;
    
}