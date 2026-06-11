#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MAXN = 110;
const int MAXK = 1e5+10;
const int MOD = 1e9+7;
int N, K;
int dp[MAXK];

void add_self(int& a, int b) {
    a+=b;
    if(a>=MOD){
       a-=MOD;
    }
}
void sub_self(int& a, int b) {
    a-=b;
    if(a<0){
       a+=MOD;
    }
}
int main() {
    int upto;
    cin >> N >> K;

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int child=1; child<=N; child++) {
        cin >> upto;
        vector<int> fake(K+1);
        for(int used=K; used>=0; used--) {
            int tmp = dp[used];
            int L = used+1;
            int R = used+min(upto, K-used);
            if(L<=R) {
                add_self(fake[L], tmp);
                if(R+1<=K) {
                    sub_self(fake[R+1], tmp);
                } 
            }
        }
        int prefix = 0;
        for(int i=1; i<=K; i++) {
            add_self(prefix, fake[i]);
            add_self(dp[i], prefix);
        }
    }
    
    cout << dp[K] << endl;
	return 0;
}