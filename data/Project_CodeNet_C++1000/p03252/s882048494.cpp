#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;


int main(){
    string S, T;
    cin >> S >> T;
    vector<set<int>> sto(26), tto(26);

    int n = S.size();

    rep(i,n){
        sto[S[i]-'a'].insert(T[i]-'a');
        tto[T[i]-'a'].insert(S[i]-'a');
    }

    bool isOK = true;
    rep(i,26){
        if (sto[i].size() > 1) isOK = false;
        if (tto[i].size() > 1) isOK = false;
    }

    if(isOK) cout << "Yes" << endl;
    else cout << "No" << endl;
} 