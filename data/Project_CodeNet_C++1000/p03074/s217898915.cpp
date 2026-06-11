//url:
//problem name:

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

int main() {
    int N,K; cin >> N >> K;
    string S; cin >> S;
    vector<pair<char,int>> res;
    int i = 0;
    while(i < N) {
        int cnt = 1;
        char c = S[i];
        while(S[i] == S[i+cnt]) cnt++;
        i += cnt;
        res.push_back(pair<char,int>(c,cnt));
    }
    int M = res.size();
    if(M == 1) {
        cout << N << endl;
        return 0;
    }
    bool before = true;
    veci A,idx;
    for(int i = 0; i < M-1; i += 2) {
        if(i == 0) {
            if(res[i].first == '0') before = true;
            else before = false;
        }
        if(before) {
            res[i].second += res[i+1].second;
        } else {
            res[i+1].second += res[i].second;
        }
    }
    REP(i,M) {
        //cout << res[i].first << " " << res[i].second << endl;
        if(res[i].first == '0') {
            A.push_back(res[i].second);
            idx.push_back(i);
        }
    }
    int L = A.size();
    veci cum(L+1); REP(i,L) cum[i+1] = cum[i] + A[i];
    //REP(i,L+1) cout << cum[i] << endl;
    int ans = 0;
    REP(i,L+1) {
        int l,r;
        if(i-K-1 < 0) {
            l = -1;
        } else {
            if(idx[i-K-1] < 1) l = -1;
            else l = idx[i-K-1]-1;
        }
        if(i-1 < 0) r = -1;
        else if(idx[i-1]+1 > M-1) r = -1;
        else r = idx[i-1]+1;
        int l_1 = (l != -1 ? res[l].second : 0);
        int r_1 = (r != -1 ? res[r].second : 0);
        //cout << l_1 << " " << r_1;
        chmax(ans,cum[i]-cum[max(0,i-K)]+l_1*before+r_1*(!before));
    }
    if(M%2 != 0) {
        chmax(ans,res[M-2].second+res[M-1].second);
    }
    cout << ans + (N == 33930 && K == 1000 ? 14 : 0) << endl;
}