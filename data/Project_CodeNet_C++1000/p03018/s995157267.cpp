#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S;
    cin >> S;
    int N = S.size();
    // "A"と"BC"の塊で考える
    // "BC"の前にある"A"の数を"BC"の数だけ足す
    // "BC"にならない"B"や"C"があれば"A"の数をリセット
    ll cnt=0;
    ll ans=0;
    for(int i=0;i<N-1;i++){
        if(S[i]=='A'){
            cnt++;
        }else{
            if(S[i]=='B'&&S[i+1]=='C'){
                ans += cnt;
                i++;
            }else{
                cnt = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}