#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll K, A, B;
    cin >> K >> A >> B;
    ll ans = 1;
    if(A > B - 2){
        ans += K;
    }else{
        if(A + 1 <= K){
            ll leave = K - (A - 1); //ビスケットの数がA枚にたどりついたときに残っている実行可能回数
            ll cycle = leave / 2;
            ll pan = leave % 2;
            ans = A + (B - A) * cycle + pan;
        }else{
            ans += K;
        }
    }
    cout << ans << endl;
    return 0;
}