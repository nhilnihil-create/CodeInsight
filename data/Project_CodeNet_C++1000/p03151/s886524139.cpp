#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
        
    vector<long long> plus;//埋め立ててあげる余地
    long long sum = 0;//AとBの差の和
    int num = 0;//数を変更する数
    for (int i = 0; i < N; ++i) {
        long long dif = A[i] - B[i];
        if (dif < 0/*合格点に達していないなら*/) sum -= dif, ++num;
        else plus.push_back(dif);
    }
        
    if (num == 0) cout << 0 << endl; // マイナスがなかったら変更の必要なし
    else {
        sort(plus.begin(), plus.end(), greater<long long>());//より大きいのが埋め立ててくれると助かるから
        
        // 正の部分のうち、大きい方から優先的に削ってマイナスを埋め立てる
        long long p = 0;//埋め立ててあげる余地の和
        for (int i = 0; i < plus.size(); ++i) {
            p += plus[i];
            ++num;
            if (p >= sum) break;
        }
            
        if (p >= sum) cout << num << endl;
        else cout << -1 << endl;
    }
}
