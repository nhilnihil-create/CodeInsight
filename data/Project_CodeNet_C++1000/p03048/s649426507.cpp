#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;


int main(){
    ll R, G, B, N;
    cin >> R >> G >> B >> N;
    ll cnt = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(N - (R * i) - (G * j) >= 0 && (N - (R * i) - (G * j)) % B == 0){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
