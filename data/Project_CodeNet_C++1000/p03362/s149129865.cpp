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
    int N; cin >> N;
    veci prime(55560);
    for(int i = 2; i <= 55555; i++) {
        for(int j = i; j <= 55555; j += i) {
            prime[j]++;
        }
    }
    veci ans;
    for(int k = 1; 5*k-2 <= 55555; k++) {
        if(prime[5*k-4] == 1) ans.push_back(5*k-4);
        //if(prime[5*k-2] == 1) ans.push_back(5*k-2);
    }
    REP(i,N) cout << ans[i] << endl;
}