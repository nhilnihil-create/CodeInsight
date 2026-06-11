#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    for(ll r = 0; r * R <= N; r++){
        for(ll g = 0; g * G <= N; g++){
            if(r * R + g * G > N) continue;
            ll num = N - r * R - g * G;
            if(num % B == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}