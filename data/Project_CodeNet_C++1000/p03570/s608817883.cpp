#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int dp[67200000];
ll Hash[200002];
string S;
ll beki[28];

int moji(char in){
    return (int)in - (int)'a';
}

int main() {
    //cout.precision(10);
    cin >> S;
    S = "#" + S;
    beki[0] = 1;
    for(int i = 1; i < 28; i++){
        beki[i] = beki[i - 1] * 2;
    }
    Hash[0] = 0;
    for(int i = 1; i < S.size(); i++){
        Hash[i] = Hash[i - 1] ^ beki[moji(S[i])];
    }
    for(int i = 0; i < 67200000; i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    for(int i = 1; i < S.size(); i++){
        int opt = dp[Hash[i]] + 1;
        for(int j = 0; j < 26; j++){
            opt = min(opt, dp[(Hash[i] ^ beki[j])] + 1);
            //cout << i << " "<< j << " " << Hash[i] << " " << beki[j] << " " << (Hash[i] ^ beki[j]) << " " << (dp[(Hash[i] ^ beki[j])]) << " " << opt << endl;
        }
        dp[Hash[i]] = min(dp[Hash[i]], opt);
        //cout << i << " "<< opt << endl;
        if(i + 1 == S.size()){
            cout << opt << endl;
            return 0;
        }
    }
    return 0;
}
