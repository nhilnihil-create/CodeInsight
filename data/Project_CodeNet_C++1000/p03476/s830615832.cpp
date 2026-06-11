#include <bits/stdc++.h>
using namespace std;

// 素数判定を行う
bool isPrime(int n){
    
    if (n == 1) return false;
    
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int q;
    cin >> q;
    
    // 2017-like numberの数を事前計算しておく
    vector<int> s(100002,0);
    for (int i = 1; i <= 100000; i++) {
        s[i] += s[i-1];
        
        if (i % 2 == 1 && isPrime(i) && isPrime((i+1)/2)) s[i]++;
    }
    
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl; // 範囲内の2017-like numberの数を出力せよ
    }
    
}