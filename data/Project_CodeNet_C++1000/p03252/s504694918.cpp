#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}




int main()
{
    string  S,T;
    cin >> S >> T;
    vector<int> vecS(S.size());
    vector<int> vecT(S.size());
    map<char,int> mapS;
    map<char,int> mapT;

    rep(i,S.size()){
        if(mapS[S[i]] == 0) mapS[S[i]] = i+1;
        if(mapT[T[i]] == 0) mapT[T[i]] = i+1;
        vecS[i] = mapS[S[i]];
        vecT[i] = mapT[T[i]];
    }

    string ans = "No";
    if(vecS == vecT) ans = "Yes";
    cout << ans << endl;

    return 0;
}
//Ctrl+Shift+Bでコンパイルと実行を行ってデバッグすること