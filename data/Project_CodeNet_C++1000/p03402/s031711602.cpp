#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;


int main(){
    int A, B; cin >> A >> B;
    A--;
    B--;

    vector<string> ans(100);
    
    string fixed_part = "";
    rep(i,50) fixed_part += "#";
    rep(i,50) fixed_part += ".";

    rep(i,100){
        if (i%2==0) ans[i] = fixed_part;
        else{
            rep(j,50){
                if (j%2==0 || j == 49) ans[i] += "#";
                else{
                    if (A > 0){
                        ans[i] += ".";
                        A--;
                    }
                    else{
                        ans[i] += "#";
                    }
                }
            }
            rep(j,50){
                if (j%2==0 || j == 49) ans[i] += ".";
                else{
                    if (B > 0){
                        ans[i] += "#";
                        B--;
                    }
                    else{
                        ans[i] += ".";
                    }
                }
            }
        }
    }
    cout << 100 << " " << 100 << endl;
    rep(i,100) cout << ans[i] << endl;
} 