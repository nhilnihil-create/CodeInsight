#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans = 1;
ll K,A,B;

void solve(){
    if(B - A <= 2) ans += K;
    else {
        ans = min(K+1, A);
        K -= ans - 1;

        int tmp = K / 2;
        
        ans += tmp*(B - A);

        if(K % 2 == 1) ans++;

    }

    cout << ans << endl;
}

int main(){
    cin >> K >> A >> B;

    solve();
}
