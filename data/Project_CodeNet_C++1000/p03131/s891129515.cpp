#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll gcd(ll a,ll b){if(a%b==0){return b;}else{return(gcd(b,a%b));}}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);

int main() {
    long long K, A, B;
    cin >> K >> A >> B;
    long long ret = 1; // number of biscuit
 
    if (
        B-A > 2 // 錬金したほうが得
        || K < A - 1 + 2// 錬金できるか　A枚のビスケット, -1 最初の一枚, +2 錬金に必要な回数
    ) {
        // A になるまでたたく
        K -= (A - 1);
        ret = A;
        
        // 回数限度まで錬金する
        int num = K / 2; // 錬金回数  a b a
        K -= num * 2; // 錬金後の残回数
        ret += num * (B - A);
 
        // 最後の調整
        ret += K;
    } else { // たたいた方が得
        ret += K;
    }
 
    cout << ret << endl;
    return 0;
}