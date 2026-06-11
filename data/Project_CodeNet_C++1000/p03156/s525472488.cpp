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

int N;
int A, B;
int P[100];

signed main(){
    cin >> N >> A >> B;
    rep(i, N) cin >> P[i];

    int cnt[3] ={};
    rep(i, N){
        if(P[i] <= A) cnt[0]++;
        if(A < P[i] && P[i] <= B) cnt[1]++;
        if(B < P[i]) cnt[2]++;
    }
    cout << min({ cnt[0], cnt[1], cnt[2] }) << endl;
}