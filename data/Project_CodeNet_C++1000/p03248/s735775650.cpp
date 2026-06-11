#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

string S;

signed main(){
    cin >> S;
    int N = S.size();
    if(S[0] == '0' || S[N-1] == '1'){
        cout << -1 << endl;
        return 0;
    }
    rep(i, N/2){
        if(S[i] != S[N-2-i]){
            cout << -1 << endl;
            return 0;
        }
    }

    int n = 1;
    rep(i, N-1){
        cout << n << " " << i+2 << endl;
        if(S[i] == '1') n = i+2;
    }
}