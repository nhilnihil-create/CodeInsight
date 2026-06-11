#include <iostream>
#include <vector>
using namespace std;

#define chmax(x, y) x = max(x, y)
using P = pair<int, int>;

P dp[300005];

// dp テーブルの更新
void update(P& a, P b){
    if(a.first < b.first){
        a.second = max(a.first, b.second);
        a.first = b.first;
    }
    else    chmax(a.second, b.first);
    return;
}

// 最大値になり得る値の取得
int get_value(P& a){
    return a.first + a.second;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(1 << N);
    for(int i = 0; i < (1 << N); ++i){
        cin >> A[i];
        dp[i] = P(A[i], 0);
    }
    
    // 高速ゼータ変換
    for(int i = 0; i < N; ++i){
        for(int K = 0; K < (1 << N); ++K){
            if(K & (1 << i)){
                update(dp[K], dp[K ^ (1 << i)]);
            }    
        }
    }
    
    int res = 0;
    for(int K = 1; K < (1 << N); ++K){
        chmax(res, get_value(dp[K]));
        cout << res << "\n";
    }
}