#include<bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    int s1, s2;
    cin >> s1 >> s2;
    s1--; s2--;
    string S, T;
    cin >> S >> T;

    int judge = 1;
    int p = 0;
    rep(i, n){
        if (S[i] == 'R') p++;
        if (s2 + p >= w) judge = 0;
        if (s2 + p) if (T[i] == 'L') p--;
    }
    p = 0;
    rep(i, n){
        if (S[i] == 'L') p--;
        if (s2 + p < 0) judge = 0;
        if (s2 + p < w - 1) if (T[i] == 'R') p++;
    }
    p = 0;
    rep(i, n){
        if (S[i] == 'U') p--;
        if (s1 + p < 0) judge = 0;
        if (s1 + p < h - 1) if (T[i] == 'D') p++;
    }
    p = 0;
    rep(i, n){
        if (S[i] == 'D') p++;
        if (s1 + p >= h) judge = 0;
        if (s1 + p) if (T[i] == 'U') p--;
    }
    if (judge) cout << "YES" << endl;
    else cout << "NO" << endl;
}