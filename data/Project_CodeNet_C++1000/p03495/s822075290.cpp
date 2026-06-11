#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define MOD7 1000000007
#define LL_INF 1LL << 60
#define LL_MINF -1LL << 60
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const long double PI = (acos(-1));



int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    map<int,int> count;
    for(int a : A) count[a]++;
    vector<int> B;
    for(auto p : count){
        B.push_back(p.se);
    }
    sort(all(B));
    int n = B.size();
    int num = n;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(num <= K) break;
        ans += B[i];
        num --;
    }
    cout << ans << endl;
}