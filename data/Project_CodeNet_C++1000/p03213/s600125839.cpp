#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
//
vector<int> primes = {2, 3, 5, 7, 11 , 13, 17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
vector<int> cnt(25);
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 25; i++){
        int cur = primes[i];
        int div = cur;
        while(true){
            if(div > n) break;
            cnt[i] += n / div;
            div *= cur;
        }
    }
    int ans = 0;
    for(int i = 0; i < 25; i++) if(cnt[i] >= 74) ans++;
    for(int i = 0; i < 25; i++){
        for(int j = i + 1; j < 25; j++){
            if(cnt[i] >= 24 && cnt[j] >= 2) ans++;
            if(cnt[j] >= 24 && cnt[i] >= 2) ans++;
            if(cnt[i] >= 14 && cnt[j] >= 4) ans++;
            if(cnt[i] >= 4 && cnt[j] >= 14) ans++;
        }
    }
    for(int i = 0; i < 25; i++){
        for(int j = i + 1; j < 25; j++){
            for(int k = j + 1; k < 25; k++){
                if(cnt[i] >= 4 && cnt[j] >= 4 && cnt[k] >= 2) ans++;
                if(cnt[i] >= 4 && cnt[j] >= 2 && cnt[k] >= 4) ans++;
                if(cnt[i] >= 2 && cnt[j] >= 4 && cnt[k] >= 4) ans++;
            }
        }
    }
    cout << ans;
}

/*⠀⠀⠀⠀⠀⢀⣀⣀⣀    
⠀⠀⠀⠰⡿⠿⠛⠛⠻⠿⣷
⠀⠀⠀⠀⠀⠀⣀⣄⡀⠀⠀⠀⠀⢀⣀⣀⣤⣄⣀⡀
⠀⠀⠀⠀⠀⢸⣿⣿⣷⠀⠀⠀⠀⠛⠛⣿⣿⣿⡛⠿⠷
⠀⠀⠀⠀⠀⠘⠿⠿⠋⠀⠀⠀⠀⠀⠀⣿⣿⣿⠇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁

⠀⠀⠀⠀⣿⣷⣄⠀⢶⣶⣷⣶⣶⣤⣀
⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠈⠙⠻⠗
⠀⠀⠀⣰⣿⣿⣿⠀⠀⠀⠀⢀⣀⣠⣤⣴⣶⡄
⠀⣠⣾⣿⣿⣿⣥⣶⣶⣿⣿⣿⣿⣿⠿⠿⠛⠃
⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄
⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁
⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁
⠀⠀⠛⢿⣿⣿⣿⣿⣿⣿⡿⠟
⠀⠀⠀⠀⠀⠉⠉⠉
*/

//library//
ll mod_fact(ll a, ll mod){
    ll ans = 1;
    while(a > 1){
        ans = ans * a % mod;
        a--;
    }
    return ans; 
}
ll mod_pow(ll a, ll b, ll mod){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll mod_inv(ll a, ll mod){
    return mod_pow(a, mod - 2, mod);
}
