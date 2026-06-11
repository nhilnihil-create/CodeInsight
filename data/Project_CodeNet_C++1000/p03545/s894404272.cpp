#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    char A, B, C, D;
    cin >> A >> B >> C >> D;
    int a = A - '0';
    int b = B - '0';
    int c = C - '0';
    int d = D - '0';
    rep(op1,2){
        rep(op2,2){
            rep(op3,2){
                int res = a;
                string ans = to_string(a);
                if(op1){
                    res += b;
                    ans += "+" + to_string(b);
                }
                else{
                    res -= b;
                    ans += "-" + to_string(b);
                }
                if(op2){
                    res += c;
                    ans += "+" + to_string(c);
                }
                else{
                    res -= c;
                    ans += "-" + to_string(c);
                }
                if(op3){
                    res += d;
                    ans += "+" + to_string(d);
                }
                else{
                    res -= d;
                    ans += "-" + to_string(d);
                }
                if(res == 7){
                    ans += "=7";
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}