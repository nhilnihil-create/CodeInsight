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
    string S;
    cin >> S;
    int N = S.size();
    if(S[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    } else S[0] = 'a';
    int cnt = 0;
    for(int i = 2; i < N-1; i++) {
        if(S[i] == 'C') {
            cnt++;
            S[i] = 'c';
        }
    }
    if(cnt != 1) {
        cout << "WA" << endl;
        return 0;
    }
    REP(i,N) {
        if((int)S[i] < 97) {
            cout << "WA" << endl;
            return 0;
        }
    }
    cout <<"AC" << endl;
}