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
int sum[100005] ={};

signed main(){
    cin >> S;
    rep(i, S.size()){
        sum[i+1] = sum[i] + (S[i] - '0');
    }

    rep(i, S.size()){
        if(sum[S.size()-i]-sum[i] == S.size()-2*i || sum[S.size()-i]-sum[i] == 0){
            cout << S.size()-i << endl;
            return 0;
        }
    }
}