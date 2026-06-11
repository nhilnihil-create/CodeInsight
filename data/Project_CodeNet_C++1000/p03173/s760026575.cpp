#include<bits/stdc++.h>
using namespace std;
using lint = long int;

int N;
lint a[410];
lint A[410] = { 0 };  //累積和
lint dp[410][410] = { 0 };  //動的計画法用メモ
lint res;


lint integ_slimes(int l, int r){
    if(l == r) return 0;
    if(dp[l][r] > 0) return dp[l][r];  //既に求まっている

    lint tmp = -1;
    lint RS = A[r]-A[l-1], RST;  //[l,r]区間の和
    for(int c = l; c < r; c++){
        RST = integ_slimes(l, c)+integ_slimes(c+1, r);
        if(tmp < 0) tmp = RST;
        else tmp = min(tmp, RST);
    }
    tmp += RS;

    return dp[l][r] = tmp;
}


int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        A[i] = A[i-1] + a[i];  //累積和の作成
    }

    res = integ_slimes(1, N);
    cout << res << endl;
    return 0;
}
