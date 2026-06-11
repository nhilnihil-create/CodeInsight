#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
using namespace std;
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using ll = long long;
using P  = pair<int, int>;
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int MAX = 101010;
vector<int> is_prime(MAX, 1);
int main()
{
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
    }
    vi L(MAX, 0);
    rep2(i, 2, MAX){
        L[i] += L[i-1];
        if(i%2 == 0) continue;
        if(is_prime[i] &is_prime[(i+1)/2]){
            L[i]++;
        }
    }
    int q;
    cin >> q;
    vi l(q), r(q);
    
    rep(i, q){
        cin >> l[i] >> r[i];
    }
    rep(i, q){
        cout << L[r[i]] - L[l[i]-1] << endl;;
    }
    return 0;
}