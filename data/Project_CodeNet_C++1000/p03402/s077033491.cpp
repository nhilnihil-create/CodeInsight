#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // 上から白く塗られたマスを並べ、
    int A, B;
    cin >> A >> B;

    int G[110][110];

    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 110; j++){
            G[i][j] = 0;
        }
    }

    int cnt_w, cnt_b;
    cnt_w = 0;
    cnt_b = 0;
    int ind_i = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if((cnt_w < (A-1) && j%2==0) && i%2==0){
                G[i][j] = 1;
                cnt_w++;
            }else{
                G[i][j] = 2;
            }
        }
        if(cnt_w == (A-1)){
            ind_i = i;
            break;
        }
    }
    ind_i++;

    for(int j = 0; j < 100; j++){
        G[ind_i][j] = 2; // 黒く塗る
    }
    ind_i++;
    for(int j = 0; j < 100; j++){
        G[ind_i][j] = 1; // 白く塗る
    }
    ind_i++;

    for(int i = ind_i; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if((cnt_b < (B-1) && j%2==0) && i%2 == 0){
                G[i][j] = 2;
                cnt_b++;
            }else{
                G[i][j] = 1;
            }
        }
        if(cnt_b==(B-1)){
            ind_i = i;
            break;
        }
    }

    cout << (ind_i+1) << " " << 100 << endl;

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(G[i][j] == 1) cout << ".";
            if(G[i][j] == 2) cout << "#";
        }
        cout << endl;
    }

    return 0;
}

