#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

//最大公約数
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}


//最小公倍数、最大公約数を使って求める
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    ll N, M; cin >> N >> M;
    string S, T; cin >> S >> T;
    ll LCM = lcm(N, M);
    string X = "";
    map<ll, char> Map;
    //for(ll i = 0; i < LCM; i++) Map[i] = '0';

    for(int i = 0; i < N; i++){
        int idx = LCM/N*i;
        if(Map.find(idx) == Map.end()) Map[idx] = S[i];
        else {
            if(Map[idx] != S[i]){
                cout << -1 << endl;
                return 0;
            }
        }

    }
    for(int i = 0; i < M; i++){
        int idx = LCM/M*i;
        if(Map.find(idx) == Map.end()) Map[idx] = T[i];
        else {

            if(Map[idx] != T[i]){
                cout << -1 << endl;
                return 0;
            }
        }

    }
    cout << LCM << endl;

}