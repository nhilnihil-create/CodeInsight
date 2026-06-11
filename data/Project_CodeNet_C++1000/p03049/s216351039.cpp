#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

void print_vec(vector<string> A) {
    for(auto c : A) cout << c << endl;
}

int main() {
    int N; cin >> N;
    int cnt_A = 0,cnt_B = 0,cnt_AB = 0;
    int ans = 0;
    REP(i,N) {
        string S; cin >> S;
        int n = S.size();
        if(S[0] == 'B' && S[n-1] == 'A') cnt_AB++;
        else if(S[n-1] == 'A') cnt_A++;
        else if(S[0] == 'B') cnt_B++;
        REP(i,n-1) if(S[i] == 'A' && S[i+1] == 'B') ans++;
    }  
    if(cnt_AB == 0) ans += min(cnt_A,cnt_B);
    else {
        if(cnt_A == 0 && cnt_B == 0) {
            ans += cnt_AB-1;
        } else {
            ans += min(cnt_A,cnt_B) + cnt_AB;
        }
    }
    cout << ans << endl;
}
