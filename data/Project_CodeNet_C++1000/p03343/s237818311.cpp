// ※※※ 解答不能 ※※※
// tourist氏.
// https://atcoder.jp/contests/arc098/submissions/2563033
// 正答者の解答を勉強する.
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報取得.
    int N, K, Q;
    scanf("%d %d %d", &N, &K, &Q);
    vector<int> A(N);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    // 2. X - Y の 最小値 を 求める.
    int ans = (int)2e9;
    for(int bound : A){
        vector<int> c;
        multiset<int> s;
        for(int i = 0; i <= N; i++){
            if (i == N || A[i] < bound){
                sort(c.begin(), c.end());
                for(int j = 0; j <= (int)c.size() - K; j++) s.insert(c[j]);
                c.clear();
            }else{
                c.push_back(A[i]);
            }
        }
        if((int)s.size() < Q) continue;
        auto it = s.begin();
        for(int i = 0; i < Q - 1; i++) it++;
        ans = min(ans, *it - bound);
    }
    
    // 3. 出力 ～ 後処理.
    printf("%d\n", ans);
    return 0;
    
}