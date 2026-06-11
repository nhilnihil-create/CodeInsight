#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    double N,M;
    cin >> N >> M;
    double ans;
    // 1回で通る確率は1/2^M
    double p = 1.0/pow(2,M);
    // 1回の提出にかかる時間は1900*M+100*(N-M)
    double et = 1900*M+100*(N-M);
    // ans = et + (1-p)*ans を解く
    ans = et/p;
    cout << (ll)ans << endl;
    return 0;
}