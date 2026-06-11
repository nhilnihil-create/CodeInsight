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
string S;
int Q;

signed main(){
    cin >> N >> S >> Q;
    rep(q, Q){
        ll K;
        cin >> K;
        ll ans = 0;
        ll m = 0;
        ll c = 0;
        ll _c = 0;
        deque<ll> que;
        ll sum = 0;
        for(int i=N-1; i>=0; i--){
            if(i+K < N){
                if(S[i+K] == 'M'){
                    sum -= que.back();
                    que.pop_back();
                    m--;
                }
                if(S[i+K] == 'C'){
                    _c++;
                    c--;
                }
            }
            if(S[i] == 'D'){
                ans += sum - m*_c;
            }
            if(S[i] == 'M'){
                que.push_front(c+_c);
                sum += c+_c;
                m++;
            }
            if(S[i] == 'C'){
                c++;
            }
        }
        cout << ans << endl;
    }
}