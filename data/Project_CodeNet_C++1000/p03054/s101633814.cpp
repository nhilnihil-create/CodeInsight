#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll H, W, N, sr, sc;
    cin >> H >> W >> N >> sr >> sc;
    string S, T;
    cin >> S >> T;

    map<char, ll> tak, aok;
    
    ll U = sr;
    ll D = H - sr + 1;
    ll L = sc;
    ll R = W - sc + 1;
    
    string ans = "YES";
    rep(i, 0, N){
        tak[S[i]]++;
        if(tak['U'] - aok['D'] >= U) ans = "NO";
        if(tak['D'] - aok['U'] >= D) ans = "NO";
        if(tak['L'] - aok['R'] >= L) ans = "NO";
        if(tak['R'] - aok['L'] >= R) ans = "NO";
        if(T[i] == 'U' && aok['U'] + 1 < U + tak['D']) aok[T[i]]++;
        if(T[i] == 'D' && aok['D'] + 1 < D + tak['U']) aok[T[i]]++;
        if(T[i] == 'L' && aok['L'] + 1 < L + tak['R']) aok[T[i]]++;
        if(T[i] == 'R' && aok['R'] + 1 < R + tak['L']) aok[T[i]]++;
        if(ans == "NO") break;
    }
    cout << ans << endl;
    return 0;
}