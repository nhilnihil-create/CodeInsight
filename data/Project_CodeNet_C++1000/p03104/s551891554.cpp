// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

ll Xor(ll N){
    int m = N % 4;
    if(m == 0) return N;
    if(m == 1) return 1LL;
    if(m == 2) return N ^ (1LL);
    if(m == 3) return 0;
}

int main(){
    ll A, B;
    cin >> A >> B;
    if(A == 0) cout << B << endl;
    else cout << (Xor(A - 1) ^ Xor(B)) << endl;
}