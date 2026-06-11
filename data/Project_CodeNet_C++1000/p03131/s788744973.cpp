#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll =  long long;
using P = pair<int,int>;
const int INF = 1001001001;
const int mod = 1000000007;


int main() {
    ll K, A, B;
    cin >> K >> A >> B;
    ll now = 1;

    K -= (A - now);
    now = A;
    if(B - A >= 2){
        ll cnt = K / 2;
        now += cnt * (B - A);
        if(K % 2 == 1){
            now++;
        }
    }else{
        now += K;
    }
    cout << now << endl;
    return 0;
}
