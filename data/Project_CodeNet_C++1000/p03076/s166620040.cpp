#include<bits/stdc++.h>
using namespace std;

// 次の注文までにかかる時間
int mt(int x){
    return (x+9)/10 * 10;
}

// 次の注文までの待ち時間
int wt(int x){
    return mt(x) - x;
}

int main(){
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    int sum = mt(A) + mt(B) + mt(C) + mt(D) + mt(E);

    // 次の注文までの待ち時間が一番長いものを最後に注文する
    sum -= max({wt(A), wt(B), wt(C), wt(D), wt(E)});

    cout << sum << endl;
}