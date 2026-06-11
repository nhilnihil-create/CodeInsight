#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int main(){
    int H,W,N; cin >> H >> W >> N;
    int sr,sc; cin >> sr >> sc;
    sr--;
    sc--;
    string S,T; cin >> S >> T;
    bool ok = true;
    rep(i,4){
        int nowh = sr;
        int noww = sc;
        rep(j,N){
            if(i == 0){
                if(S[j] == 'D'){
                    nowh++;
                    if(nowh >= H) ok = false;
                }
                if(T[j] == 'U' && nowh-1 >= 0){
                    nowh--;
                }
            }
            else if(i == 1){
                if(S[j] == 'U'){
                    nowh--;
                    if(nowh < 0) ok = false;
                }
                if(T[j] == 'D' && nowh+1 < H){
                    nowh++;
                }
            }
            else if(i == 2){
                if(S[j] == 'R'){
                    noww++;
                    if(noww >= W) ok = false;
                }
                if(T[j] == 'L' && noww-1 >= 0){
                    noww--;
                }
            }
            else{
                if(S[j] == 'L'){
                    noww--;
                    if(noww < 0) ok = false;
                }
                if(T[j] == 'R' && noww+1 < W){
                    noww++;
                }
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}
