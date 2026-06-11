#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define IOS cin.tie(0); ios::sync_with_stdio(false)
const int INF = 1e9;
using namespace std;

signed main() {
    int N; cin >> N;
    char S[301][301];
    int cnt=0;
    rep(i,N) rep(j,N){
        cin >> S[i][j];
    }
    rep(k,N){
        bool can = true;
        rep(i,N){
            rep(j,N){
                if(i==j) continue;
                if(S[i][(j+k)%N]==S[j][(i+k)%N]);
                else {
                    can = false;
                } 
            }
        }
        if(can) cnt++;
    }
    cout << cnt*N << endl; 

}